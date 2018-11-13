// Wrote by MenYifan on 2015-07-23 19:58:21
// Exe.Time 0ms Exe.Memory 692K
//
//  20150723i.cpp
//  Cfiles
//
//  Created by ??? on 15/7/23.
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
ll euler(ll x) {
    ll res = x;
    for (ll i = 2; i <= x / i; i++) if (x % i == 0) {
        res = res / i * (i - 1);
        while(x % i == 0) x /= i;
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
int main(){
    int n;
    while (sf(n),n) {
        cout<<euler(n)<<endl;
    }
}