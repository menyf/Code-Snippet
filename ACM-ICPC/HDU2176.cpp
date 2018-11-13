// Wrote by MenYifan on 2015-07-22 11:30:08
// Exe.Time 62ms Exe.Memory 2356K
//
//  20150722a.cpp
//  Cfiles
//
//  Created by ??? on 15/7/22.
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
int main(){
    int n,a[200000+50],tmp;
    while (sf(n),n) {
        int ans=0;
        for (int i=0; i<n; i++) {
            sf(a[i]);
            ans=ans^a[i];

        }
        if (ans==0) {
            pf("No\n");
            continue;
        }
        pf("Yes\n");
        for (int i=0; i<n; i++) {
            tmp=ans^a[i];
            if (a[i]>tmp) {
                pf("%d %d\n",a[i],tmp);
            }
        }
        
    }
}