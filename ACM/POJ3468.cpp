// Wrote by MenYifan on 2015-10-18 19:27:37
// Exe.Time 1922ms Exe.Memory 4804K
//
//  20151018e.cpp
//  Cfiles
//
//  Created by ??? on 15/10/18.
//  Copyright   2015? ???. All rights reserved.
//

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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 100005;
ll add[NV<<2],sum[NV<<2];
void PushUp(ll rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(ll rt,ll m)
{
    if (add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * (m - (m >> 1));
        sum[rt<<1|1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void build(ll l,ll r,ll rt=1)
{
    add[rt] = 0;
    if (l == r)
    {
        scanf("%lld",&sum[rt]);

        return ;
    }
    ll m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(ll L,ll R,ll c,ll l,ll r,ll rt=1)
{
    if (L <= l && r <= R)
    {
        add[rt] += c;
        sum[rt] += c * (r - l + 1);
        return ;
    }
    PushDown(rt , r - l + 1);
    ll m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (m < R) update(L , R , c , rson);
    PushUp(rt);
}
ll query(ll L,ll R,ll l,ll r,ll rt=1)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    ll m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L , R , lson);
    if (m < R) ret += query(L , R , rson);
    return ret;
    
}
int main(){
    ll n,q,a,b,c,ans;
    scanf("%lld %lld",&n,&q);
    char s[2];
    build(1, n, 1);
    for (ll i=0; i<q; i++) {
        scanf("%s",s);
        if (s[0]=='Q') {
            scanf("%lld %lld",&a,&b);
            cout<<query( a, b, 1, n)<<endl;
        }
        else{
            scanf("%lld %lld %lld",&a,&b,&c);
            update(a, b, c, 1, n);
        }
    }
}