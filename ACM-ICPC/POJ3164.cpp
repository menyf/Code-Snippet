// Wrote by MenYifan on 2016-09-05 14:06:59
// Exe.Time 110ms Exe.Memory 752K
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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#define debug3(x,y,z) cout<<"Debug : ---"<<x<<" , "<<y<<" , "<<z<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

typedef double mytype;
const int Vmax=105;
const int Emax=Vmax*Vmax;
struct point{
    int x,y;
}p[105];
double dis(point a,point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y-b.y) * (a.y - b.y));
}
struct edge
{
    int u,v;
    mytype l;
} E[Emax];
int pre[Vmax],ID[Vmax],vis[Vmax];
mytype In[Vmax];
void init(int m)
{
    for(int i=1; i<=m; i++){
        scanf("%d%d",&E[i].u,&E[i].v);
        E[i].l = dis(p[E[i].u], p[E[i].v]);
    }
}
mytype Directed_MST(int root,int NV,int NE)
{
    //    memset(pre,0,sizeof(pre));
    mytype ret = 0;
    while(1)
    {
        //1.?????
        for(int i=1; i<=NV; i++)
            In[i] = INF;
        for(int i=1; i<=NE; i++)
        {
            int u = E[i].u;
            int v = E[i].v;
            if(E[i].l < In[v] && u != v)
            {
                pre[v] = u;
                In[v] = E[i].l;
            }
        }
        for(int i=1; i<=NV; i++)
        {
            if(i == root)
                continue;
            if(fabs(In[i]-INF)<eps)
                return -1;//???????????,???????
        }
        //2.??
        int cntnode = 0;
        memset(ID,-1,sizeof(ID));
        memset(vis,-1,sizeof(vis));
        In[root] = 0;
        for(int i=1; i<=NV; i++) //?????
        {
            ret += In[i];
            int v = i;
            while(vis[v] != i && ID[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && ID[v] == -1)
            {
                ID[v] = ++cntnode;
                for(int u = pre[v] ; u != v ; u = pre[u])
                    ID[u] = cntnode;
            }
        }
        if(cntnode == 0)
            break;//??
        for(int i=1; i<=NV; i++)
            if(ID[i] == -1)
                ID[i] = ++cntnode;
        //3.??,????
        for(int i=1; i<=NE; i++)
        {
            int v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if(E[i].u != E[i].v)
            {
                E[i].l -= In[v];
            }
        }
        NV = cntnode;
        root = ID[root];
    }
    return ret;
}
bool judge(mytype ans)
{
    return fabs(ans+1)>eps;
}
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        init(m);
        double ans = Directed_MST(1, n, m);
        if (judge(ans)) {
            printf("%.2f\n",ans);
        }
        else{
            printf("poor snoopy\n");
        }
    }
}