// Wrote by MenYifan on 2016-08-25 12:09:11
// Exe.Time 15ms Exe.Memory 1608K
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
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
#define RMQ max
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[maxn<<2]={};
void pushup(int rt){
    sum[rt]=RMQ(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt=1){
    if (l==r){
        scanf("%d",sum+rt);
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
    int m=(l+r)>>1;
    if (pos<=m) update(pos, val, lson);
    else update(pos, val, rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt=1){
    if (L<=l&&r<=R) return sum[rt];
    int m=(l+r)>>1;
    int res=0;
    if (L<=m) res=RMQ(res,query(L, R, lson));
    if (R>m)  res=RMQ(res,query(L, R, rson));
    return res;
}
int main(){
    int T;
    int n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        build(1, n);
        int q;
        scanf("%d",&q);
        int l,r;
        while (q--) {
            scanf("%d%d",&l,&r);
            cout<<query(l, r, 1, n)<<endl;
        }

    }
}