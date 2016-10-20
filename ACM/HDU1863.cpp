//
//  1863kruskal.cpp
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
#define Emax 1000   //最大边数量
#define Vmax 300    //最大点数量
struct Kruskal{
    int n,m;//n个点 m条边
    int rank[Vmax],fa[Vmax];//并查集需要
    int weight;// weight为最小生成树的重量
    
    struct edge{
        int u,v,w;//起点 终点 权值
        bool operator<(const edge e) const{
            return w<e.w;
        }
    }e[Emax];
    
    void init(int Vsz,int Esz){
        n=Vsz;m=Esz;
        for(int i=0;i<=Vsz;i++){
            fa[i]=i;
            rank[i]=0;
        }
    }
    
    //边的编号从0～m-1
    void adde(int id,int u,int v,int w){
        e[id].u=u;
        e[id].v=v;
        e[id].w=w;
    }
    
    int findx(int x){
        while(x!=fa[x])
            x=fa[x];
        return x;
    }
    
    void set_merge(int u,int v){
        if(rank[u]<rank[v]){
            fa[u]=v;
            rank[v]+=rank[u];
        }
        else{
            fa[v]=u;
            rank[u]+=rank[v];
        }
    }
    
    bool kruskal(){
        int cnt=0;
        weight=0;
        sort(e,e+m);
        for(int i=0;i<m;i++){
            int uR=findx(e[i].u);
            int vR=findx(e[i].v);
            if(uR!=vR){
                set_merge(uR, vR);
                weight+=e[i].w;
                cnt++;
            }
        }
        if(cnt==n-1) return true;//最小生成树可建
        else return false; //最小生成树不可建
    }
}k;
int main(){
    int n,m,u,v,d;
    while (sf(n)&&n) {
        sf(m);
        k.init(m,n);
        for (int i=0; i<n; i++) {
            sfff(u, v, d);
            k.adde(i, u, v, d);
        }
        if (k.kruskal())
            printf("%d\n",k.weight);
        else
            printf("?\n");
    }
}
