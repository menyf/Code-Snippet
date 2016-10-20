// Wrote by MenYifan on 2015-11-15 22:26:03
// Exe.Time 15ms Exe.Memory 1604K
//
//  20151115j.cpp
//  Cfiles
//
//  Created by ??? on 15/11/15.
//  Copyright   2015? ???. All rights reserved.
//

#include <stdio.h>
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
int main(){
    int n,m,k,s;
    while (scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF) {
        int dp[110][110]={};//vis[1]???? vis[0]??????
        int a[100]={};
        int b[100]={};
        for (int i=0; i<k; i++) {
            scanf("%d%d",&a[i],&b[i]);
        }
        
        for (int i=0; i<k; i++) {
            for (int j=b[i]; j<=m; j++) {
                for (int p=1; p<=s; p++) {
                    dp[j][p]=max(dp[j][p], dp[j-b[i]][p-1]+a[i]);
                }
            }
        }
        
        bool flag=false;
        for (int i=0; i<=m; i++) {
            for (int j=1; j<=s; j++) {
                if (dp[i][j]>=n) {
                    printf("%d\n",m-i);
                    flag=true;
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            continue;
        }
        printf("-1\n");
    }
}