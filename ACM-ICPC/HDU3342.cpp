//
//  3342SPFA.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/8/14.
//  Copyright (c) 2015年 门一凡. All rights reserved.
//  本来想练习一下SPFA，结果SPFA不能处理(正)环
//http://acm.hust.edu.cn/vjudge/contest/view.action?cid=75216#problem/D

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
#define INF 0x3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define Vmax 150
int path[Vmax][Vmax];
int main(){
    int n,m,x,y;
    while (sff(n, m)&&n) {
        bool flag=true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                path[i][j]=INF;
            }
        }
        
        while (m--) {
            sff(x, y);
            path[x][y]=0;
        }
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if (path[i][k]!=INF&&path[k][j]!=INF&&path[i][k]+path[k][j]<path[i][j])
                        path[i][j]=path[i][k]+path[k][j];
        
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (!path[i][j]&&!path[j][i]) {
                    flag=false;
                    break;
                }
        
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
