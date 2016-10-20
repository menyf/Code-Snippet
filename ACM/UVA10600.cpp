// Wrote by MenYifan on 2016-09-05 10:09:52
// Exe.Time 0ms Exe.Memory 0K
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

// ????1?n
const int Vmax = 105;
namespace SMST{
    // MST
    int n;//n???
    int s;//?? ???
    int weight; //MST???
    int mp[Vmax][Vmax];
    int dis[Vmax];  //dis[i]????i??????
    bool vis[Vmax]; //?????????
    int pre[Vmax];//????
    
    //SMST
    int subweight; //SMST???
    bool used[Vmax][Vmax];  //???????????
    int maxd[Vmax][Vmax];   //maxd[u][v]?? u-v????????
    
    void init(int Vsz,int source=1){//?????1
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
    
    //1~n?????
    void adde(int u,int v,int w){
        mp[u][v]=w;
        mp[v][u]=w;
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
            used[pos][pre[pos]] = true; // for SMST
            used[pre[pos]][pos] = true; // for SMST
            vis[pos]=true;
            
            for(int j=1;j<=n;j++){
                if (j == pos) continue;
                if(vis[j]) {
                    maxd[j][pos] = maxd[pos][j] = max(dis[pos], maxd[j][pre[pos]]);
                }
                else if(!vis[j]&&mp[pos][j]<dis[j]){
                    dis[j]=mp[pos][j];
                    pre[j]=pos;
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
        for(int i = 1; i<= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(mp[i][j]!=INF && !used[i][j]){
                    subweight = min(subweight, weight+mp[i][j]-maxd[i][j]);
                }
            }
        }
        if(subweight == INF) return -2; //??????? ??????????? ???????
        return subweight;
    }
}
using namespace SMST;
int main(){
    int T,n,m,u,v,w;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init(n);
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            adde(u, v, w);
        }
        smst();
        printf("%d %d\n",weight,subweight);
    }
}