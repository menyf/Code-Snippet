//
//  20150807.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/8/7.
//  Copyright (c) 2015年 门一凡. All rights reserved.
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
#define vset(a,val) memset(a,val,sizeof(a))
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
#define maxn 6005
vector<int>adj[maxn];
int indeg[maxn];
int val[maxn];
int f[maxn][2];
int vis[maxn];
int n,m;
void dfs(int pos){
    vis[pos]=true;
    f[pos][0]=0;
    f[pos][1]=val[pos];
    for (int i=0; i<adj[pos].size(); i++) {
        int tmp=adj[pos][i];
        if (vis[tmp]) {
            continue;
        }
        dfs(tmp);
        f[pos][0]+=max(f[tmp][1],f[tmp][0]);
        f[pos][1]+=f[tmp][0];
    }
}
int main(){
    while (sf(n)!=EOF) {
        for (int i=1; i<=n; i++)
            adj[i].clear();
        
        for (int i=1; i<=n; i++)
            sf(val[i]);
        
        vset(indeg, 0);
        int u,v;
        while (~sff(v, u)&&v+u) {
            adj[u].push_back(v);
            indeg[v]++;
        }
        vset(f, 0);
        for (int i=1; i<=n; i++) {
            if (!indeg[i]) {
                vset(vis, 0);
                dfs(i);
                printf("%d\n",max(f[i][0],f[i][1]));
                break;
            }
        }
    }
}
