// Wrote by MenYifan on 2015-10-18 19:11:17
// Exe.Time 0ms Exe.Memory 0K
//
//  20151018a.cpp
//  Cfiles
//
//  Created by ??? on 15/10/18.
//  Copyright  2015? ???. All rights reserved.
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=1005;
int G[maxn][maxn];//????
int n;
int m;
int c[maxn];
int topo[maxn],t;
bool dfs(int u)
{
    c[u]=-1;//????
    for (int v=0; v<n; v++)
    {
        if (G[u][v])
        {
            if (c[v]<0) return false;
            else if (!c[v]&&!dfs(v)) return false;
        }

    }
    c[u]=1;
    topo[--t]=u;
    return true;
}
bool toposort()
{
    t=n;
    memset(c,0,sizeof(c));
    for (int u=0; u<n; u++)
        if (!c[u]&&!dfs(u)) return false;
    return true;
}
int main()
{

    while (scanf("%d %d",&n,&m)!=EOF)
    {
        if (n==0&&m==0)
            break;
        memset(G, 0, sizeof(G));
        for (int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[u-1][v-1]=1;
        }
        toposort();
        for (int i=0; i<n; i++)
        {
            if (i==0)
                printf("%d",topo[i]+1);
            else
                printf(" %d",topo[i]+1);
        }
        printf("\n");
    }
    return 0;
}