// Wrote by MenYifan on 2016-09-05 12:01:36
// Exe.Time 10ms Exe.Memory 0K
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

// ????1?n
const int Vmax = 105;
namespace SMST{
    struct Edge{
        int u,v,next,w,vis;
    }e[405];
    int ecnt;
    int he[Vmax];
    
    // MST
    int n;//n???
    int s;//?? ???
    int weight; //MST???
    int dis[Vmax];  //dis[i]????i??????
    bool vis[Vmax]; //?????????
    int pre[Vmax];//????
    
    //SMST
    int subweight; //SMST???
    int id[Vmax];
    int maxd[Vmax][Vmax];   //maxd[u][v]?? u-v????????
    
    void init(int Vsz,int source=1){//?????1
        memset(he, -1, sizeof(he));
        ecnt = 0;
        memset(dis, INF, sizeof(dis));
        memset(maxd, 0, sizeof(maxd));
        memset(vis, false, sizeof(vis));
        n=Vsz;
        weight=0;
        dis[source] = 0;
        pre[source] = source;
        s = source;
    }
    
    //1~n?????
    void adde(int u,int v,int w){
        e[ecnt].vis = 0;
        e[ecnt].u = u;
        e[ecnt].v = v;
        e[ecnt].w = w;
        e[ecnt].next = he[u];
        he[u] = ecnt ++;
    }
    
    int prim(){
        /*
         ??????
         -1: ????
         weight: ????????
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
            if(minc == INF) return -1; //n????? ????
            
            weight+=dis[pos];
            vis[pos]=true;
            if (i!=s) {
                e[id[pos]].vis = 1;
                e[id[pos]^1].vis = 1;
            }
            
            for(int j=1;j<=n;j++){
                if (j == pos) continue;
                if(vis[j]) {
                    maxd[j][pos] = maxd[pos][j] = max(dis[pos], maxd[j][pre[pos]]);
                }
            }
            for (int j = he[pos]; j!=-1; j = e[j].next) {
                int v = e[j].v;
                if (!vis[v] && e[j].w < dis[v]) {
                    dis[v] = e[j].w;
                    pre[v] = pos;
                    id[v] = j;
                }
            }
        }

        return weight;
    }
    
    int smst(){
        /*
         ??????
         -1: ????
         -2: ?????? ?????? ?????????????
         subweight: ????????
         */
        if(prim() == -1) return -1; //????
        subweight = INF;
        for (int i=0; i<ecnt; i+=2) {
            int u = e[i].u;
            int v = e[i].v;
            if (e[i].vis == 0) {
                subweight = min(subweight, weight + e[i].w - maxd[u][v]);
            }
        }
        if(subweight == INF) return -2; //??????? ??????????? ???????
        return subweight;
    }
}
using namespace SMST;
int main(){
    int T,n,m,u,v,w,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init(n);
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            adde(u, v, w);
            adde(v, u, w);
        }
        
        int ans = smst();
        printf("Case #%d : ",cas++);
        if (ans == -1)
            printf("No way\n");
        else if (ans == -2)
            printf("No second way\n");
        else
            printf("%d\n",subweight);
    }
}