// Wrote by MenYifan on 2015-07-25 16:00:28
// Exe.Time 15ms Exe.Memory 1728K
//
//  20150724f.cpp
//  Cfiles
//
//  Created by ??? on 15/7/25.
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
double any(int n){
    if (n==1||n==0)
        return 1.0;
    else
        return n*any(n-1);
}
int main(){
    int n,m;
    while (sff(n, m)!=EOF) {
        int a[11];
        double tmp[maxn],ans[maxn]={1.0};
        for (int i=0; i<n; i++) {
            sf(a[i]);
        }
        for (int i=0; i<=a[0]; i++) {
            ans[i]=1.0/any(i);
        }
        for (int i=1; i<n; i++) {
            for (int j=0; j<maxn; j++) {
                for (int k=0; k<=a[i]&&j+k<=m; k++) {
                    tmp[j+k]+=ans[j]/any(k);
                }
            }
            memcpy(ans, tmp, sizeof(ans));
            memset(tmp, 0, sizeof(tmp));
        }
        pf("%.0f\n",ans[m]*any(m));
    }
}