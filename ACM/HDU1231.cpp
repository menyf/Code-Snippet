// Wrote by MenYifan on 2015-11-15 19:06:07
// Exe.Time 202ms Exe.Memory 1676K
//
//  20151115i.cpp
//  Cfiles
//
//  Created by ??? on 15/11/15.
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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int a[maxn],b[maxn];
int dp[maxn];
int main(){
    int n;
    while (scanf("%d",&n),n) {
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        memset(dp, -1, sizeof(dp));
        
        for (int i=1; i<=n; i++) {
            if (dp[i-1]<0) {
                b[i]=i;
                dp[i]=a[i];
            }
            else{
                b[i]=b[i-1];
                dp[i]=dp[i-1]+a[i];
            }
        }
        int index,mx=-1;
        for (int i=1; i<=n; i++) {
            if (dp[i]>mx) {
                mx=dp[i];
                index=i;
            }
        }
        if (mx==-1) {
            printf("%d %d %d\n",0,a[1],a[n]);
        }
        else
            printf("%d %d %d\n",mx,a[b[index]],a[index]);
    
    }

}