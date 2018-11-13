// Wrote by MenYifan on 2015-07-24 11:39:20
// Exe.Time 15ms Exe.Memory 1616K
//
//  20150723b.cpp
//  Cfiles
//
//  Created by ??? on 15/7/24.
//  Copyright (c) 2015? ???. All rights reserved.
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
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 10005
ll qPow1(ll A,ll n)//???
{
    //?a^n
    if (n == 0) return 1;
    ll rslt = 1;
    
    while (n)
    {
        if (n & 1)
        {
            rslt =rslt*A;
        }
        A = A*A;
        n >>= 1;
    }
    return rslt;
}
int main(){
    ll n,ans;
    int t;
    cin>>t;
    while (t--) {
        scanf("%lld",&n);
        ans=qPow1(3, n);
        cout<<ans<<endl;
    }
}