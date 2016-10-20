// Wrote by MenYifan on 2016-08-13 15:35:14
// Exe.Time 10ms Exe.Memory 0K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

const int Vmax=2005; //??????????
namespace MCMF{
    struct Edge{
        int from,to,cap,flow,cost;
        Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
    };
    
    int n,m;
    vector<Edge>edges;
    vector<int>G[Vmax];
    int inq[Vmax];  //??????
    int d[Vmax];    //Bellman-Ford
    int p[Vmax];    //????
    int a[Vmax];    //????
    
    void init(int _n){
        n=_n;
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }
    
    void adde(int from,int to,int cap,int cost){
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
    bool SPFA(int s,int t,int& flow,long long& cost){
        for(int i=0;i<=n;i++) d[i]=INF;
        memset(inq, 0, sizeof(inq));
        d[s]=0;
        inq[s]=1;
        p[s]=0;
        a[s]=INF;
        
        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost; //????
                    p[e.to]=G[u][i];    //????????
                    a[e.to]=min(a[u], e.cap-e.flow);
                    if(!inq[e.to]){
                        q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF) return false; //s-t ????????
        flow+=a[t];
        cost+=(long long)d[t]*(long long)a[t];
        for(int u=t;u!=s;u=edges[p[u]].from){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        return true;
    }
    
    int MincostMaxflow(int s,int t,long long& cost){
        int flow=0;
        cost=0;
        while(SPFA(s, t, flow, cost));
        return flow;
    }
}
int main(){
    int n,m,x,y,w;
    while (scanf("%d%d",&n,&m)!=EOF) {
        // ??
        MCMF::init(2*n);
        MCMF::adde(1, n+1, 2, 0);
        MCMF::adde(n, 2*n, 2, 0);
        for (int i=2; i<n; i++) {
            MCMF::adde(i, i+n, 1, 0);
        }
        
        //??
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&x,&y,&w);
            MCMF::adde(x+n, y, 1, w);
        }
        
        //???
        ll mc;
        MCMF::MincostMaxflow(1, n+n, mc);
        cout<<mc<<endl;
    }
    return 0;
}