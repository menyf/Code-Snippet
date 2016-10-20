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
const int Vmax = 1000+10;  //最大顶点数
const int Emax = 10000+10; //最大边数
map<PII, int>mp;
struct Dinic{
    int src,target,ecnt;//源点，汇点，边数
    int head[Vmax];//邻接表表头
    int cur[Vmax];
    int dis[Vmax];//从源点到该点的距离
    struct edge{
        int to,next,cap;
    }e[2*Emax];//边可能是双向的，故乘2
    
    void init(int start,int end){
        ecnt=0;
        src=start;
        target=end;
        memset(head,-1,sizeof(head));
    }
    
    void adde(int from,int to,int cap){
        e[ecnt].to=to;
        e[ecnt].cap=cap;
        e[ecnt].next=head[from];
        head[from]=ecnt++;
        
        e[ecnt].to=from;
        e[ecnt].cap=0;
        e[ecnt].next=head[to];
        head[to]=ecnt++;
    }
    
    bool BFS(){
        memset(dis, -1, sizeof(dis));
        dis[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            for(int i=head[tmp];i!=-1;i=e[i].next){
                int tp=e[i].to;
                if(dis[tp]==-1&&e[i].cap){
                    dis[tp]=dis[tmp]+1;
                    q.push(tp);
                    if(tp==target)
                        return true;
                }
            }
        }
        return false;
    }
    
    int DFS(int u,int delta){
        if(u==target||delta==0)
            return delta;
        int f,flow=0;
        for(int& i=cur[u];i!=-1;i=e[i].next){
            if(dis[u]+1==dis[e[i].to] && (f=DFS(e[i].to,min(delta,e[i].cap))))
            {
                e[i].cap-=f;
                e[i^1].cap+=f;
                flow+=f;
                delta-=f;
                if(!delta)break;
            }
        }
        return flow;
    }
    
    int dinic(){
        int tmp=0,maxflow=0;
        while(BFS()){
            for(int i=src;i<=target;i++) cur[i]=head[i];
            while(tmp=DFS(src, INF))
                maxflow+=tmp;
        }
        return maxflow;
    }
}d;
namespace SPFA {
    int he[Vmax],ecnt;
    struct edge{
        int v,w,next;
    }e[Emax*2];
    int vis[Vmax];
    int dis[Vmax];
    int vcnt[Vmax];//记录每个点进队次数，用于判断是否出现负环
    bool inq[Vmax];
    vector<int> pre[Vmax];  //记录最短路中的上一个节点
    void init(){
        ecnt=0;
        memset(vcnt,0,sizeof(vcnt));
        memset(he,-1,sizeof(he));
        memset(inq, false, sizeof(inq));
    }
    //***注意双向加边
    void adde(int from,int to,int w){
        e[ecnt].v=to;
        e[ecnt].w=w;
        e[ecnt].next=he[from];
        he[from]=ecnt++;
    }
    bool SPFA(int n,int source){//n为顶点数 source为起点
        //return true表示无负环，反之亦然
        for (int i=0; i<=n; i++)
            dis[i]=INF;
        dis[source]=0;
        queue<int>q;
        q.push(source);inq[source]=true;
        
        while (!q.empty()) {
            int tmp=q.front();
            q.pop();inq[tmp]=false;
            
            //判断负环
            vcnt[tmp]++;
            if (vcnt[tmp]>=n) return false;
            
            for (int i=he[tmp]; i!=-1; i=e[i].next) {
                int w=e[i].w;
                int v=e[i].v;
                if (dis[tmp]+w<dis[v]) {
                    dis[v]=dis[tmp]+w;  //松弛操作
                    pre[v].clear();
                    pre[v].push_back(tmp);
                    if (!inq[v]) {
                        q.push(v);
                        inq[v]=true;
                    }
                }
                else if(dis[tmp] + w == dis[v]){
                    pre[v].push_back(tmp);
                }
            }
        }
        return true;
    }
    int get_ans(int n,int source,int destination){
        SPFA(n,source);
        return dis[destination];
    }
    void bfs(int n){
        memset(vis, 0, sizeof(vis));
        queue<int>q;
        q.push(n);
        vis[n] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0 ; i<pre[u].size(); i++) {
                int v = pre[u][i],w;
                if (v < u)  w = mp[make_pair(v, u)];
                else w = mp[make_pair(u, v)];
                d.adde(v, u, w);
                if (vis[v] == 0) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    
}


int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        mp.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        SPFA::init();
        while (m--) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if (u > v) swap(u, v);
            mp[make_pair(u, v)] = w;
            SPFA::adde(u, v, 1);
            SPFA::adde(v, u, 1);
        }
        SPFA::SPFA(n, 1);
        d.init(1, n);
        SPFA::bfs(n);
        cout<<d.dinic()<<"\n";
    }
}
