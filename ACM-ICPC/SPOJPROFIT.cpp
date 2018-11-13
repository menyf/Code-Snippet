// Wrote by MenYifan on 2016-08-17 17:04:46
// Exe.Time 240ms Exe.Memory 13312K
// poj 2987
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
#define debug(x) cout<<"Debug : >>>"<<x<<"<<<"<<endl;
#define debug2(x,y) cout<<"Debug : >>>"<<x<<" , "<<y<<"<<<"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int Vmax = 55000+10;
const int Emax = 160900;
namespace ISAP{
    int n;
    struct Node {
        int v;    // vertex
        ll cap;    // capacity
        ll flow;   // current flow in this arc
        int nxt;
    } e[Emax * 2];
    int he[Vmax], fcnt;
    int st, ed;
    ll dist[Vmax], numbs[Vmax], q[Vmax];
    void adde(int u, int v, ll c) {    //???????
        e[++fcnt].v = v;
        e[fcnt].cap = c;
        e[fcnt].flow = 0;
        e[fcnt].nxt = he[u];
        he[u] = fcnt;
        e[++fcnt].v = u;
        e[fcnt].cap = 0;
        e[fcnt].flow = 0;
        e[fcnt].nxt = he[v];
        he[v] = fcnt;
    }
    void init(int src,int sink,int n_) {
        memset(he, 0, sizeof(he));
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
            for (int i = he[u]; i; i = e[i].nxt) {
                if (e[i ^ 1].cap == 0 || dist[e[i].v] < Vmax) continue;
                dist[e[i].v] = dist[u] + 1;
                ++numbs[dist[e[i].v]];
                q[rear++] = e[i].v;
            }
        }
    }
    ll maxflow() {
        rev_bfs();
        ll u, totalflow = 0;
        ll curg[Vmax], revpath[Vmax];
        for(ll i = 0; i <= n; ++i) curg[i] = he[i];
        u = st;
        while(dist[st] < n) {
            if(u == ed) {   // find an augmenting path
                ll augflow = INF;
                for(ll i = st; i != ed; i = e[curg[i]].v)
                    augflow = min(augflow, e[curg[i]].cap);
                for(ll i = st; i != ed; i = e[curg[i]].v) {
                    e[curg[i]].cap -= augflow;
                    e[curg[i] ^ 1].cap += augflow;
                    e[curg[i]].flow += augflow;
                    e[curg[i] ^ 1].flow -= augflow;
                }
                totalflow += augflow;
                u = st;
            }
            ll i;
            for(i = curg[u]; i; i = e[i].nxt)
                if(e[i].cap > 0 && dist[u] == dist[e[i].v] + 1) break;
            if(i) {   // find an admissible arc, then Advance
                curg[u] = i;
                revpath[e[i].v] = i ^ 1;
                u = e[i].v;
            } else {    // no admissible arc, then relabel this vertex
                if(0 == (--numbs[dist[u]])) break;    // GAP cut, Important!
                curg[u] = he[u];
                ll mindist = n;
                for(ll j = he[u]; j; j = e[j].nxt)
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
    int n,m,tmp,u,v;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        ISAP::init(0, n+m+1, n+m+2);
        ll sum = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&tmp);
            ISAP::adde(m+i, m+n+1, tmp);
        }
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&u,&v,&tmp);
            ISAP::adde(0, i, tmp);
            ISAP::adde(i, u+m, INF);
            ISAP::adde(i, v+m, INF);
            sum += tmp;
        }
        ll ans = sum - ISAP::maxflow();
        cout<<ans<<endl;
    }
    return 0;
}