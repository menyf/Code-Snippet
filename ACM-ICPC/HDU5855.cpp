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
#define IN freopen("1012.in","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int Vmax=2005; //需要拆点的话记得加倍
namespace ISAP{
    const int Emax = 420900;
    ll n;
    struct Node {
        int v;    // vertex
        ll cap;    // capacity
        ll flow;   // current flow in this arc
        int nxt;
    } e[Emax * 2];
    ll g[Vmax], fcnt;
    ll st, ed;
    ll dist[Vmax], numbs[Vmax], q[Vmax];
    void adde(int u, int v, ll c) {    //单向加边的过程
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
    void init(ll src,ll sink,ll n_) {
        memset(g, 0, sizeof(g));
        fcnt = 1;
        n=n_;
        st = src, ed = sink;/*修改*/
    }
    void rev_bfs() {
        ll font = 0, rear = 1;
        for (ll i = 0; i <= n; i++) { //n为总点数
            dist[i] = Vmax;
            numbs[i] = 0;
        }
        q[font] = ed;
        dist[ed] = 0;
        numbs[0] = 1;
        while(font != rear) {
            ll u = q[font++];
            for (ll i = g[u]; i; i = e[i].nxt) {
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
        for(ll i = 0; i <= n; ++i) curg[i] = g[i];
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
                curg[u] = g[u];
                ll mindist = n;
                for(ll j = g[u]; j; j = e[j].nxt)
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
struct plant{
    ll L,t;
    int id;
    void in(){
        scanf("%lld %lld",&L,&t);
    }
    bool operator < (const plant &pp)const{
        return t<pp.t;
    }
}p[205];
vector<int>lnk[Vmax];
int V[Vmax];
int rnk[Vmax];
int main(){
    int T;
    int k,tmp;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++) {
        int n,m; ll L;
        scanf("%d%d%lld",&n,&m,&L);
        
        for (int i=1; i<=n; i++) {
            p[i].in();
            p[i].id = i ;
        }
        sort(p+1, p+1+n);
        
        for (int i=1; i<=n; i++) {
            tmp = p[i].id;
            rnk[tmp] = i;
        }
        
        for (int i=1; i<=m; i++) {
            lnk[i].clear();
            scanf("%d",V+i);
            scanf("%d",&k);
            while (k--) {
                scanf("%d",&tmp);
                lnk[i].push_back(rnk[tmp]);
            }
            sort(lnk[i].begin(), lnk[i].end());
        }

        int l = 1 ,r = n;
        
        ll tt = -1, ans = 0, sum = 0, pre = -1, pro;
        while (l<=r) {
            int mid = ( l + r ) >> 1;
            ISAP::init(0, n+m+1, (n+m)+2);
            
            sum = 0;
            for (int i=1; i<=m; i++) {
                if (lnk[i].back()>mid) continue;
                ISAP::adde(0, i, V[i]);
                sum += V[i];
            }
            
            for (int i=1; i<=m; i++) {
                if (lnk[i].back()>mid) continue;
                int sz = (int)lnk[i].size();
                for (int j=0; j<sz; j++) {
                    ISAP::adde(i, m+lnk[i][j], INF);
                }
            }
            
            for (int i=1; i<=mid; i++) {
                ISAP::adde(i+m, 1+n+m, p[i].L);
            }
            
            ans = sum - ISAP::maxflow();
            if (ans < L) {
                l = mid+1;
            }
            else if (ans > L){
                r = mid-1, tt = p[mid].t, pro = ans;
            }
            else{
                tt = p[mid].t, pro = ans;
                break;
            }
        }
        
        printf("Case #%d: ",cas);
        if (tt!=-1)
            printf("%lld %lld\n",tt,pro);
        else
            printf("impossible\n");
    }
    return 0;
}
