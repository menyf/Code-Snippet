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
int a[maxn], b[maxn], rt[20*maxn], ls[20*maxn], rs[20*maxn], sum[20*maxn];

int n, q, tot, sz;

void build(int& id, int l, int r){
    id = ++ tot;
    sum[id] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(ls[id], l, m);
    build(rs[id], m + 1, r);
}

void update(int& id, int l, int r, int pre, int rk){
    id = ++ tot;
    ls[id] = ls[pre];
    rs[id] = rs[pre];
    sum[id] = sum[pre] + 1;
    if(l == r) return;
    int m = (l + r) >> 1;
    if(rk <= m)  update(ls[id], l, m, ls[pre], rk);
    else update(rs[id], m + 1, r, rs[pre], rk);
}

int query(int ss, int tt, int l, int r, int k){
    if(l == r) return l;
    int m = (l + r) >> 1;
    int cnt = sum[ls[tt]] - sum[ls[ss]];
    if(k <= cnt) return query(ls[ss], ls[tt], l, m, k);
    else return query(rs[ss], rs[tt], m + 1, r, k - cnt);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        tot = 0; //初始化

        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++){
            scanf("%d", a + i);
            b[i] = a[i];
        }
    
        stable_sort(b+1, b+1+n);
        int sz=unique(b+1, b+1+n)-b-1;
        for (int i=1; i<=n; i++)
            a[i]=lower_bound(b+1, b+sz+1, a[i])-b;

        build(rt[0],1, sz); //建树
        
        for(int i = 1; i <= n; i ++)    //加点
            update(rt[i], 1, sz, rt[i - 1], a[i]);
        
        while(q--) {
            int L,R,K;
            scanf("%d%d%d",&L,&R,&K);
            int idx = query(rt[L - 1], rt[R], 1, sz, K);
            printf("%d\n",b[idx]); // 输出[L, R]第K大
        }
    }
    return 0;
}

