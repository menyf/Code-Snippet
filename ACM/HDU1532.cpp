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
#define vmax 205  //最大顶点数
#define emax 205 //最大边数
struct Dinic{
    int src,sink,ecnt;//源点，汇点，边数
    int head[vmax];//邻接表表头
    int cur[vmax];
    int dis[vmax];//从源点到该点的距离
    struct edge{
        int to,next,cap;
    }e[2*emax];//边可能是双向的，故乘2
    
    void init(int start,int end){
        ecnt=0;
        src=start;
        sink=end;
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
                    if(tp==sink)
                        return true;
                }
            }
        }
        return false;
    }
    
    int DFS(int u,int delta){
        if(u==sink||delta==0)
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
           for(int i=src;i<=sink;i++) cur[i]=head[i];
            while(tmp=DFS(src, INF))
                maxflow+=tmp;
        }
        return maxflow;
    }
};
int main(){
    int n,m,s,t,c;
    while (scanf("%d%d",&n,&m)!=EOF) {
        Dinic d;
        d.init(1, m);
        while (n--) {
            sfff(s, t, c);
            d.adde(s, t, c);
        }
        cout<<d.dinic()<<endl;
    }
}
