// Wrote by MenYifan on 2015-07-24 17:22:19
// Exe.Time 15ms Exe.Memory 1732K
//
//  20150724a.cpp
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
#define maxn 10500
int main(){
    int n,ans,sum;
    int m[maxn],p[maxn];
    while (scanf("%d",&n),n) {
        ans=0;
        sum=0;
        for (int i=0; i<n; i++) {
            sff(p[i], m[i]);
            sum+=p[i]*m[i];
        }
        if (sum%3) {
            pf("sorry\n");
            continue;
        }
        int tmp[maxn]={};
        int ans[maxn]={1};
        for (int i=0; i<n; i++) {
            for (int j=0; j<=m[i]; j++) {
                for (int k=0; k+j*p[i]<=sum; k++) {
                    tmp[k+j*p[i]]+=ans[k];
                }
            }
            for (int j=0; j<=sum; j++) {
                ans[j]=tmp[j];
                tmp[j]=0;
                ans[j]%=10000;
            }
        }
        pf("%d\n",ans[sum/3]);
    }
}