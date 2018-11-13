// Wrote by MenYifan on 2015-08-13 23:49:23
// Exe.Time 15ms Exe.Memory 2132K
//
//  2544dijkstra.cpp
//  Cfiles
//
//  Created by ??? on 15/8/13.
//  Copyright (c) 2015? ???. All rights reserved.
//  ?????????????? o(m*log(n))

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
struct Edge{
    int from,to, dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct HeapNode{
    int d,u;
    bool operator < (const HeapNode& rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];        //???????
    int d[maxn];            //s(??)???????
    int p[maxn];            //?????????
    
    void init(int n){
        this->n=n;
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }
    
    void adde(int from,int to,int dist){
        edges.push_back(Edge(from-1, to-1, dist));
        m=edges.size();
        G[from-1].push_back(m-1);
    }
    
    void dijkstra(int s){
        priority_queue<HeapNode> q;
        for(int i=0;i<n;i++) d[i]=INF;
        d[s]=0;
        memset(done, 0, sizeof(done));
        q.push((HeapNode){0,s});
        while(!q.empty()){
            HeapNode x=q.top();q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
    
    int get_ans(int source,int destination){
        dijkstra(source-1);
        return d[destination-1];
    }
};
int main(){
    Dijkstra d;
    int x,y,dis;
    int m,n;
    while (sff(n, m)&&m+n) {
        d.init(n);
        while (m--) {
            sfff(x, y, dis);
            d.adde(x, y, dis);
            d.adde(y, x, dis);
        }
        cout<<d.get_ans(1, n)<<endl;
    }
}