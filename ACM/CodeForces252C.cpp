// Wrote by MenYifan on 2015-10-09 21:22:20
// Exe.Time 92ms Exe.Memory 776K
//
//  20151009c.cpp
//  Cfiles
//
//  Created by ??? on 15/10/9.
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
#define maxn 100005
int main(){
    ll ans,n,d;
    ll a[maxn]={};
    scanf("%lld %lld",&n,&d);
    for (ll i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    }
    ll i=0,j=2;
    while (i<n-2) {
        if (a[j]-a[i]<=d&&j<n) {
            j++;
        }
        else{
            ans+=(j-i-1)*(j-i-2)/2;
            i++;
        }
    }
    cout<<ans<<endl;
}