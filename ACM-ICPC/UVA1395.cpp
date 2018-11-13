// Wrote by MenYifan on 2015-11-23 21:34:31
// Exe.Time 1803ms Exe.Memory 0K
//
//  20151122e.cpp
//  Cfiles
//
//  Created by ??? on 15/11/23.
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
#define Vmax 200    //?????
#define Emax 5000   //?????
struct Kruskal{
    int n,m;//n?? m??
    int rank[Vmax],fa[Vmax];//?????
    int weight;// weight?????????
    
    struct edge{
        int u,v,w;//?? ?? ??
        bool operator<(const edge e) const{
            return w<e.w;
        }
    }e[Emax];
    
    Kruskal(int Vsz,int Esz):n(Vsz),m(Esz){};
    
    void init(){
        for(int i=0;i<=n;i++){
            fa[i]=i;
            rank[i]=0;
        }
    }
    
    //?????0?m-1
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
    
    int kruskal(int start){
        int cnt=0;
        int mx=0;
        
        sort(e,e+m);
        int mn=e[start].w;
        
        for(int i=start;i<m;i++){
            int uR=findx(e[i].u);
            int vR=findx(e[i].v);
            if(uR!=vR){
                set_merge(uR, vR);
                mx=e[i].w;
                weight+=e[i].w;
                cnt++;
            }
        }
        if(cnt==n-1) return mx-mn;//???????
        else return -1; //????????
    }
};
int main(){
    int n,m,u,v,w;
    while (scanf("%d%d",&n,&m),n) {
        int index=0,ans=INF;
        
        Kruskal tree(n,m);
        for (int i=0; i<m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            tree.adde(index++, u, v, w);
        }
        
        for (int i=0; i<m; i++) {
            tree.init();
            int tmp=tree.kruskal(i);
            if (tmp!=-1) {
                ans=min(ans, tmp);
            }
        }
        
        if (ans==INF) {
            ans=-1;
        }
        printf("%d\n",ans);
        
    }
}