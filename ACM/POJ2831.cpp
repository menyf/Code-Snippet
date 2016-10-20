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

// 顶点下标1～n
const int Vmax = 1005;
namespace SMST{
    // MST
    int n;//n个顶点
    int s;//起点 树的根
    int weight; //MST的重量
    int mp[Vmax][Vmax];
    int dis[Vmax];  //dis[i]表示指向i点的最短的边
    bool vis[Vmax]; //标记该点是否在树上
    int pre[Vmax];//记录前驱
    
    //SMST
    int subweight; //SMST的重量
    bool used[Vmax][Vmax];  //表示当前边有没有被用过
    int maxd[Vmax][Vmax];   //maxd[u][v]表示 u-v路径上最大的边权
    
    void init(int Vsz,int source=1){//默认起点为1
        memset(mp, INF, sizeof(mp));
        memset(dis, INF, sizeof(dis));
        memset(used, 0, sizeof(used));
        memset(maxd, 0, sizeof(maxd));
        memset(vis, false, sizeof(vis));
        n=Vsz;
        for (int i=0; i<=n; i++) {
            mp[i][i] = 0;
        }
        weight=0;
        dis[source] = 0;
        pre[source] = source;
    }
    
    //1~n的邻接矩阵
    void adde(int u,int v,int w){
        if (mp[u][v] == INF) {
            mp[u][v]=w;
            mp[v][u]=w;
        }
        else{
            mp[u][v]=min(mp[u][v], w);
            mp[v][u]=mp[u][v];
        }
    }
    
    int prim(){
        /*
         返回值说明：
         -1: 无生成树
         weight: 最小生成树的重量
         */
        
        for(int i=1;i<=n;i++){
            int pos=0;
            int minc = INF;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&dis[j]<minc){
                    pos=j;
                    minc = dis[j];
                }
            }
            if(minc == INF) return -1; //n个点不联通 无生成树
            
            weight+=dis[pos];
            used[pos][pre[pos]] = true; // for SMST
            used[pre[pos]][pos] = true; // for SMST
            vis[pos]=true;
            
            for(int j=1;j<=n;j++){
                if (j == pos) {
                    continue;
                }
                if(vis[j]) {
                    maxd[j][pos] = maxd[pos][j] = max(dis[pos], maxd[j][pre[pos]]);
                }
                if(!vis[j]&&mp[pos][j]<dis[j]){
                    dis[j]=mp[pos][j];
                    pre[j]=pos;
                }
            }
            
        }
        return weight;
    }
    
    int smst(){
        /*
         返回值说明：
         -1: 无生成树
         -2: 有最小生成树 无次小生成树 （比如给出的图即为一棵树）
         subweight: 次小生成树的重量
         */
        if(prim() == -1) return -1; //无生成树
        subweight = INF;
        for(int i = 1; i<= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(mp[i][j]!=INF && !used[i][j]){
                    subweight = min(subweight, weight+mp[i][j]-maxd[i][j]);
                }
            }
        }
        if(subweight == INF) return -2; //只有唯一生成树 也就是说只有最小生成树 没有次小生成树
        return subweight;
    }
}
struct node{
    int u,v;
}p[1000000+5];
int main(){
    int u,v,w,n,m,q,i,x;
    while (scanf("%d%d%d",&n,&m,&q)!=EOF) {
        SMST::init(n);
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            SMST::adde(u, v, w);
            p[i].u = u, p[i].v = v;
        }
        SMST::prim();
        
        while (q--) {
            scanf("%d%d",&i,&x);
            u = p[i].u, v = p[i].v;
            if (SMST::maxd[u][v] >= x) {
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }
}
