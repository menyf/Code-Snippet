//
//  2458kruskal.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/8/15.
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int fa[505];
struct edge{
    int u,v,w;
};
int findx(int x){
    while (x!=fa[x])
        x=fa[x];
    return x;
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main(){
    int t;
    sf(t);
    while (t--) {
        int n,ecnt=0,ans=0;
        sf(n);
        edge e[n*n];
        for (int i=1; i<=n; i++) {
            fa[i]=i;
            for (int j=1; j<=n; j++) {
                sf(e[ecnt].w);
                e[ecnt].u=i;
                e[ecnt++].v=j;
            }
        }
        sort(e, e+ecnt, cmp);
        for (int i=0; i<ecnt; i++) {
            int ur=findx(e[i].u);
            int vr=findx(e[i].v);
            if (ur!=vr) {
                fa[ur]=vr;
                if (e[i].w>ans) {
                    ans=e[i].w;
                }
            }
        }
        cout<<ans<<endl;
    }
}
