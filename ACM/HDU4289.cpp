// Wrote by MenYifan on 2016-08-13 16:51:50
// Exe.Time 62ms Exe.Memory 2872K
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

namespace ISAP{
    const int Vmax = 205*2;
    const int Emax = 20005*3;
    int n;
    struct Node {
        int v;    // vertex
        int cap;    // capacity
        int flow;   // current flow in this arc
        int nxt;
    } e[Emax * 2];
    int g[Vmax], fcnt;
    int st, ed;
    int dist[Vmax], numbs[Vmax], q[Vmax];
    void adde(int u, int v, int c) {    //???????
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
    }
    void rev_bfs() {
        int font = 0, rear = 1;
        for (int i = 0; i <= n; i++) { //n????
            dist[i] = Vmax;
            numbs[i] = 0;
        }
        q[font] = ed;
        dist[ed] = 0;
        numbs[0] = 1;
        while(font != rear) {
            int u = q[font++];
            for (int i = g[u]; i; i = e[i].nxt) {
                if (e[i ^ 1].cap == 0 || dist[e[i].v] < Vmax) continue;
                dist[e[i].v] = dist[u] + 1;
                ++numbs[dist[e[i].v]];
                q[rear++] = e[i].v;
            }
        }
    }
    int maxflow() {
        rev_bfs();
        int u, totalflow = 0;
        int curg[Vmax], revpath[Vmax];
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
    int n,m,x,y,w,st,ed;
    
    while (scanf("%d%d",&n,&m)!=EOF) {
        scanf("%d%d",&st,&ed);
        
        ISAP::init(st, ed+n, n*2);
        
        for (int i=1; i<=n; i++) {
            scanf("%d",&w);
            ISAP::adde(i, i+n, w);
        }
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&x,&y);
            ISAP::adde(x+n, y, INF);
            ISAP::adde(y+n, x, INF);
        }
        cout<<ISAP::maxflow()<<endl;
    }

    return 0;
}