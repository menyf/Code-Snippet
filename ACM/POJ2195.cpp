// Wrote by MenYifan on 2016-08-13 11:19:11
// Exe.Time 94ms Exe.Memory 1520K
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
const int maxn=200+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Edge{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};
struct MCMF{
    int n,m;
    vector<Edge>edges;
    vector<int>G[maxn];
    int inq[maxn];  //??????
    int d[maxn];    //Bellman-Ford
    int p[maxn];    //????
    int a[maxn];    //????
    
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
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
        for(int i=0;i<n;i++) d[i]=INF;
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
};
struct node{
    int x,y;
    node(){}
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
    int operator - (const node &a){
        return abs(a.x-x)+abs(a.y-y);
    }
}man[1000],house[1000];
char mp[1000][1000];
int main(){;
    int N,M;
    while (scanf("%d%d",&N,&M),N&&M) {
        
        MCMF p;
        for (int i=0; i<N; i++) {
            scanf("%s",mp[i]);
        }
        int mcnt = 0;
        int hcnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (mp[i][j]=='H') {
                    house[hcnt++] = node(i,j);
                }
                else if(mp[i][j]=='m'){
                    man[mcnt++] = node (i,j);
                }
            }
        }
        
        int st = 0,ed =hcnt+mcnt +1;
        int cnt = hcnt + mcnt + 2;

        p.init(cnt);
        
        
        for (int i=1; i<=mcnt; i++) {
            p.adde(0, i, 1, 0);
        }
        for (int i=1; i<=hcnt; i++) {
            p.adde(mcnt+i, ed, 1, 0);
        }
        
        for (int i=0; i<mcnt; i++) {
            for (int j=0; j<hcnt; j++) {
                p.adde(i+1, mcnt+j+1, 1, man[i]-house[j]);
            }
        }
        
        ll mc,mf;
        mf = p.MincostMaxflow(st, ed, mc);
        cout<<mc<<endl;
    }
}