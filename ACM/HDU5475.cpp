// Wrote by MenYifan on 2016-08-23 14:15:28
// Exe.Time 2074ms Exe.Memory 3652K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int mod;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll sum[maxn<<2];
void pushup(int rt){
    sum[rt]=(sum[rt<<1]*sum[rt<<1|1])%mod;
}
void build(int l,int r,int rt=1){
    if (l==r) {
        sum[rt]=1LL;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int pos,int val,int l,int r,int rt=1){
    if (l==r) {
        sum[rt]=val;
        return;
    }
    int m = ( l + r ) >> 1;
    if (pos<=m)
        update(pos, val, lson);
    else
        update(pos, val, rson);
    pushup(rt);
}
ll query(int L,int R,int l,int r,int rt=1){
    if (L<=l&&r<=R)
        return sum[rt];
    int m=(l+r)>>1;
    ll res=1;
    if (L<=m)
        res=(res*query(L, R, lson))%mod;
    if (R>m)
        res=(res*query(L, R, lson))%mod;
    return res;
}
int main(){
    int q;
    int T,op,cas=1,tmp;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&q,&mod);
        build(1, q);
        printf("Case #%d:\n",cas++);
        for (int i=1; i<=q; i++) {
            scanf("%d%d",&op,&tmp);
            if (op==1) {
                update(i, tmp, 1, q);
            }
            else{
                update(tmp, 1, 1, q);
            }
            cout<<query(1, q, 1, q)<<endl;
        }
    }
    return 0;
}
