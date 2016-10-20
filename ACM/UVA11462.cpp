// Wrote by MenYifan on 2015-10-07 18:18:32
// Exe.Time 275ms Exe.Memory 0K
//
//  20151007e.cpp
//  Cfiles
//
//  Created by ??? on 15/10/7.
//  Copyright   2015? ???. All rights reserved.
//  Age Sort

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
#define maxn 10005
int main(){
    int n,tmp;
    int a[105]={};
    while (scanf("%d",&n),n) {
        vset(a, 0);
        int t=0;
        for (int i=0; i<n; i++) {
            sf(tmp);
            a[tmp]++;
        }
        
        for (int i=1; i<=100; i++) {
            if (a[i]!=0) {
                for (int j=0; j<a[i]; j++) {
                    t++;
                    printf("%d",i);
                    if (t==n) {
                        printf("\n");
                    }
                    else
                        printf(" ");
                }
            }
        }
    }
}