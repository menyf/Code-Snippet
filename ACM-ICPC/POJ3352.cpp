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
const double eps=1e-11;
//求无向图的割顶和桥
const int Vmax=100000+10;    //顶点数
const int Emax=100000+10;    //顶点数
int dfs_clock;//时钟，每访问一个节点增1
int pre[Vmax];//pre[i]表示i节点被第一次访问到的时间戳,若pre[i]==0表示i还未被访问
int low[Vmax];//low[i]表示i节点及其后代能通过反向边连回的最早的祖先的pre值
bool iscut[Vmax];//标记i节点是不是一个割点
int in[Vmax];
int cut[Vmax];//cut[i]表示割i点的时图中联通分量的增加量
vector<pair<int, int> >Bridge;
struct Edge{
    int v,next;
}e[Emax*2];
int he[Vmax],ecnt=0;
void adde(int u,int v){
    e[ecnt].v=v;
    e[ecnt].next = he[u];
    he[u] = ecnt++;
}

int dfs(int u,int fa=-1)//求出以u为根节点(u在DFS树中的父节点是fa)的树的所有割顶和桥
{
    if (fa == -1) cut[u]--; //如果是根的话，割时增加的量为“连出去的量减一”
    int lowu=pre[u]=++dfs_clock;
    int child=0;    //子节点数目
    for (int i=he[u]; i!=-1; i=e[i].next) {
        int v=e[i].v;
        if(!pre[v]){
            child++;//未访问过的节点才能算是u的孩子
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u]){
                cut[u]++;
                iscut[u]=true;      //u点是割顶
                if(lowv>pre[u]) //割桥判定
                    Bridge.push_back(make_pair(u, v));
            }
        }
        else if(pre[v]<pre[u] && v!=fa){//v!=fa确保了(u,v)是从u到v的反向边
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0 && child==1 )
        iscut[u]=false;//u若是根且孩子数<=1,那u就不是割顶
    return low[u]=lowu;
}
void work(int n,int m){
    // input & initialize
    memset(he, -1, sizeof(he));
    ecnt = 0;
    dfs_clock=0;//初始化时钟
    memset(in, 0, sizeof(in));
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(cut, 0, sizeof(cut));
    Bridge.clear();
    
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);//下标1~n
        adde(u, v);
        adde(v, u);
    }
    
    //Apllication
    int k = 0;
    for (int i=1; i<=n; i++) {
        if (!pre[i]) {
            k++;
            dfs(i);//每次遍历一个连通块
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j = he[i]; j!=-1; j=e[j].next) {
            int v = e[j].v;
            if (low[i]!=low[v]) {
                in[low[v]]++;
            }
        }
    }
    
    int leaf = 0;
    for (int i=1; i<=n; i++) {
        if (in[i]==1) {
            leaf ++;
        }
    }
    cout<<(leaf + 1)/2<<"\n";
}
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        work(n, m);
    }
}
