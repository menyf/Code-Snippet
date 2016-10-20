// Wrote by MenYifan on 2015-08-05 19:57:23
// Exe.Time 79ms Exe.Memory 984K
//
//  20150805b.cpp
//  Cfiles
//
//  Created by ??? on 15/8/5.
//  Copyright (c) 2015? ???. All rights reserved.
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
#define maxn 10005
int a[maxn];
struct edge{
    int from,to,cap,flow;
    edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKarp{
    int n,m;
    vector<edge>e;
    vector<int>g[maxn];
    int a[maxn];
    int p[maxn];
    void init(int n){
        for(int i=0;i<n;i++)
            g[i].clear();
        e.clear();
    }
    void adde(int from,int to,int cap){
        e.push_back(edge(from, to, cap, 0));
        e.push_back(edge(to, from, 0, 0));
        m=e.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    int maxflow(int s,int t){
        int flow=0;
        while(1){
            vset(a, 0);
            queue<int>q;
            q.push(s);
            a[s]=INF;
            while(!q.empty()){
                int tmp=q.front();q.pop();
                for(int i=0;i<g[tmp].size() ;i++){
                    edge& etmp=e[g[tmp][i]];
                    if(!a[etmp.to]&&etmp.cap>etmp.flow){
                        p[etmp.to]=g[tmp][i];
                        a[etmp.to]=min(a[tmp], etmp.cap-etmp.flow);
                        q.push(etmp.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=e[p[u]].from){
                e[p[u]].flow+=a[t];
                e[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};
int main(){
    int n,f,d,fcnt,dcnt,tmp;
    while (sfff(n, f, d)!=EOF) {
        EdmondsKarp e;
        e.init(n);
        for (int i=1; i<=f; i++) {
            e.adde(0, i, 1);
        }
        for (int i=1; i<=d; i++) {
            e.adde(2*n+f+i, 2*n+f+d+1, 1);
        }
        for (int i=1; i<=n; i++) {
            e.adde(i+f, i+f+n, 1);
            sff(fcnt, dcnt);
            for (int j=1; j<=fcnt; j++) {
                sf(tmp);
                e.adde(tmp, i+f, 1);
            }
            for (int j=1; j<=dcnt; j++) {
                sf(tmp);
                e.adde(i+n+f, 2*n+f+tmp, 1);
            }
        }
        cout<<e.maxflow(0, 2*n+f+d+1);
    }
}