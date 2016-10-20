// Wrote by MenYifan on 2015-11-07 19:15:36
// Exe.Time 30ms Exe.Memory 4K
//
//  20151107a.cpp
//  Cfiles
//
//  Created by ??? on 15/11/7.
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
int main(){
    int a[4][4],sum;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    
    for (int i=0; i<100005; i++) {
        
        a[1][1]=i;
        sum=a[1][1]+a[1][2]+a[1][3];
        a[2][2]=sum-a[2][1]-a[2][3];
        a[3][3]=sum-a[1][3]-a[2][3];
    
        
        if (i+a[2][2]+a[3][3]==sum) {
            for (int k=1; k<=3; k++) {
                for (int j=1; j<=3; j++) {
                    printf("%d",a[k][j]);
                    if (j!=3) {
                        printf(" ");
                    }
                    else
                        printf("\n");
                }
            }
            return 0;
        }
    }
    return 0;
}