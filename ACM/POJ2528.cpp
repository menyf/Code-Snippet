// Wrote by MenYifan on 2015-10-18 22:00:55
// Exe.Time 438ms Exe.Memory 1648K
//
//  20151018f.cpp
//  Cfiles
//
//  Created by ??? on 15/10/18.
//  Copyright   2015? ???. All rights reserved.
//  Mayor's posters
//  ???+???
//  ????????

#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define vset(a,val) memset(a,val,sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 100005;
int add[NV<<2],sum[NV<<2];
void PushUp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if (add[rt])
    {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = add[rt] * (m - (m >> 1));
        sum[rt<<1|1] = add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void build(int l,int r,int rt=1)
{
    add[rt] = 0;
    if (l == r)
    {
        sum[rt]=0;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        add[rt] = c;
        sum[rt] = c * (r - l + 1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (m < R) update(L , R , c , rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L , R , lson);
    if (m < R) ret += query(L , R , rson);
    return ret;
}

int main(){
    int t;
    int n;
    sf(t);
    while (t--) {
        set<int>st;
        sf(n);
        int v[2*(n+1)],tmp[2*(n+1)],a[2*(n+1)];
        for (int i=1; i<=2*n; i++) {
            scanf("%d",v+i);
        }
        /****???****/
        memcpy(tmp, v, sizeof(tmp));
        stable_sort(tmp+1, tmp+1+2*n);
        int cnt=unique(tmp+1, tmp+1+2*n)-tmp-1;
        for (int i=1; i<=2*n; i++)
            a[i]=lower_bound(tmp+1, tmp+cnt+1, v[i])-tmp;


        build(1, cnt);
        
        for (int i=1; i<=n; i++) {
            update(a[2*i-1], a[2*i], i, 1, cnt);
        }
        for (int i=1; i<=cnt; i++) {
            int x=query(i, i, 1, cnt);
            st.insert(x);
        }
        cout<<st.size()<<endl;
    }
}