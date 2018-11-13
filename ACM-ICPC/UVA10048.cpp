// Wrote by MenYifan on 2015-11-25 11:35:43
// Exe.Time 6ms Exe.Memory 0K
//
//  20151122g.cpp
//  Cfiles
//
//  Created by ??? on 15/11/25.
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
int mp[105][105];
int main(){
    bool flag=false;
    int cas=0,c,s,q,ans,u,v,w;
    while (scanf("%d%d%d",&c,&s,&q),c) {
        if (flag) printf("\n");
        ans=0;
        memset(mp, INF, sizeof(mp));
        
        for (int i=1; i<=s; i++) {
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=w;
            mp[v][u]=w;
        }
        
        for (int k=1; k<=c; k++) {
            for (int i=1; i<=c; i++) {
                for (int j=1; j<=c; j++) {
                    mp[i][j]=min(mp[i][j], max(mp[i][k], mp[k][j]));
                }
            }
        }
        
        printf("Case #%d\n",++cas);
        
        for (int i=1; i<=q; i++) {
            scanf("%d%d",&u,&v);
            if (mp[u][v]==INF)
                printf("no path\n");
            else
                printf("%d\n",mp[u][v]);
        }
        
        flag=true;
    }
}