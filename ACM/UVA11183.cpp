// Wrote by MenYifan on 2016-09-05 14:30:32
// Exe.Time 30ms Exe.Memory 0K
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

typedef int mytype;
const int Vmax=1005;
const int Emax=40005;
struct edge//???
{
    int u,v;    //?? ??
    mytype l;   //??
} e[Emax];
int pre[Vmax],ID[Vmax],vis[Vmax];
mytype In[Vmax];
void init(int m)
{
    for(int i=1; i<=m; i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
        e[i].u ++ ,e[i].v++;
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
            int u = e[i].u;
            int v = e[i].v;
            if(e[i].l < In[v] && u != v)
            {
                pre[v] = u;
                In[v] = e[i].l;
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
            int v = e[i].v;
            e[i].u = ID[e[i].u];
            e[i].v = ID[e[i].v];
            if(e[i].u != e[i].v)
            {
                e[i].l -= In[v];
            }
        }
        NV = cntnode;
        root = ID[root];
    }
    return ret;
}
bool judge(mytype ans)  //??????
{
    return fabs(ans+1)>eps;
}
int main(){
    int T,n,m,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init(m);
        int ans = Directed_MST(1, n, m);
        printf("Case #%d: ",cas++);
        if (judge(ans)) {
            printf("%d\n",ans);
        }
        else{
            puts("Possums!");
        }
    }
}