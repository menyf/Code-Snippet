// Wrote by MenYifan on 2016-08-13 14:15:12
// Exe.Time 4992ms Exe.Memory 10228K
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define inf 0x3f3f3f3f
#define debug puts("-----")
#define maxn 100000+5
#define ll long long
#define LL long long
#define NE 3000
#define mx 10005
#define ep 1e-2
#define pi acos(-1.0)
#define mod 1000000007

///===================================////
#define INF 0x3f3f3f3f
namespace ISAP{
    const int Emax = 420900;
    int n;
    struct Node {
        int v;    // vertex
        int cap;    // capacity
        int flow;   // current flow in this arc
        int nxt;
    } e[Emax * 2];
    int g[maxn], fcnt;
    int st, ed;
    int dist[maxn], numbs[maxn], q[maxn];
    void adde(int u, int v, int c) {
        e[++fcnt].v = v;
        e[fcnt].cap = c;
        e[fcnt].flow = 0;
        e[fcnt].nxt = g[u];
        g[u] = fcnt;
        e[++fcnt].v = u;
        e[fcnt].cap = 0;
        e[fcnt].flow = 0;
        e[fcnt].nxt = g[v];
        g[v] = fcnt;
    }
    void init(int src,int sink,int n_) {
        memset(g, 0, sizeof(g));
        fcnt = 1;
        n=n_;
        st = src, ed = sink;/*??*/
        //n = n + 3; //?????n??????
    }
    void rev_bfs() {
        int font = 0, rear = 1;
        for (int i = 0; i <= n; i++) { //n????
            dist[i] = maxn;
            numbs[i] = 0;
        }
        q[font] = ed;
        dist[ed] = 0;
        numbs[0] = 1;
        while(font != rear) {
            int u = q[font++];
            for (int i = g[u]; i; i = e[i].nxt) {
                if (e[i ^ 1].cap == 0 || dist[e[i].v] < maxn) continue;
                dist[e[i].v] = dist[u] + 1;
                ++numbs[dist[e[i].v]];
                q[rear++] = e[i].v;
            }
        }
    }
    int maxflow() {
        rev_bfs();
        int u, totalflow = 0;
        int curg[maxn], revpath[maxn];
        for(int i = 0; i <= n; ++i) curg[i] = g[i];
        u = st;
        while(dist[st] < n) {
            if(u == ed) {   // find an augmenting path
                int augflow = INF;
                for(int i = st; i != ed; i = e[curg[i]].v)
                    augflow = min(augflow, e[curg[i]].cap);
                for(int i = st; i != ed; i = e[curg[i]].v) {
                    e[curg[i]].cap -= augflow;
                    e[curg[i] ^ 1].cap += augflow;
                    e[curg[i]].flow += augflow;
                    e[curg[i] ^ 1].flow -= augflow;
                }
                totalflow += augflow;
                u = st;
            }
            int i;
            for(i = curg[u]; i; i = e[i].nxt)
                if(e[i].cap > 0 && dist[u] == dist[e[i].v] + 1) break;
            if(i) {   // find an admissible arc, then Advance
                curg[u] = i;
                revpath[e[i].v] = i ^ 1;
                u = e[i].v;
            } else {    // no admissible arc, then relabel this vertex
                if(0 == (--numbs[dist[u]])) break;    // GAP cut, Important!
                curg[u] = g[u];
                int mindist = n;
                for(int j = g[u]; j; j = e[j].nxt)
                    if(e[j].cap > 0) mindist = min(mindist, dist[e[j].v]);
                dist[u] = mindist + 1;
                ++numbs[dist[u]];
                if(u != st)
                    u = e[revpath[u]].v;    // Backtrack
            }
        }
        return totalflow;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,x,y,r,l,lx,rx,tmp;
        scanf("%d%d",&n,&m);
        l=1,r=1;
        scanf("%d%*d",&lx);
        rx = lx;
        for (int i=2; i<=n; i++) {
            scanf("%d%*d",&x);
            if (x<lx) {
                lx = x;
                l = i;
            }
            if (x>rx) {
                rx = x;
                r = i;
            }
        }
        ISAP::init(l, r, n);
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&x,&y,&tmp);
            ISAP::adde(x, y, tmp);
            ISAP::adde(y, x, tmp);
        }
        cout<<ISAP::maxflow()<<endl;
    }
    
}