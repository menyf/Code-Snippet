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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll eps=1e-8;
const int maxn=100000+10;
const int Vmax = 2e5 + 10;
const int Emax = 2e6 + 10;
int he[Vmax],ecnt;
struct edge{
    int v,next;
    ll w;
}e[Emax*2];
ll dis1[Vmax];
ll dis2[Vmax];
int vcnt[Vmax];//记录每个点进队次数，用于判断是否出现负环
bool inq[Vmax];
int pre[Vmax];  //记录最短路中的上一个节点
void init(){
    ecnt=0;
    memset(he,-1,sizeof(he));
}
//***注意双向加边
void adde(int from,int to,ll w){
    e[ecnt].v=to;
    e[ecnt].w=w;
    e[ecnt].next=he[from];
    he[from]=ecnt++;
}
bool SPFA(int n,int source,ll *dis){//n为顶点数 source为起点
    //return true表示无负环，反之亦然
    for (int i=0; i<=n; i++)
        dis[i]=INF;
    dis[source]=0;
    queue<int>q;
    q.push(source);inq[source]=true;
    
    while (!q.empty()) {
        int tmp=q.front();
        q.pop();inq[tmp]=false;
        //判断负环
        vcnt[tmp]++;
        if (vcnt[tmp]>=n) return false;
        
        for (int i=he[tmp]; i!=-1; i=e[i].next) {
            ll w=e[i].w;
            int v=e[i].v;
            if (dis[tmp]+w<dis[v]) {
                dis[v]=dis[tmp]+w;  //松弛操作
                pre[v]=tmp;
                if (!inq[v]) {
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return true;
}
ll get_ans(int n,int source,int destination,ll *dis){
    memset(vcnt,0,sizeof(vcnt));
    memset(inq, false, sizeof(inq));
    SPFA(n,source, dis);
    return dis[destination];
}
vector<int>ans;
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n,m,t;
        init();
        scanf("%d%d",&n,&m);
        for (int i=1; i<=m; i++) {
            scanf("%d",&t);
            int k,tmp;
            scanf("%d",&k);
            for (int j = 0; j<k; j++) {
                scanf("%d",&tmp);
                adde(tmp, n+i, t);
                adde(n+i, tmp, t);
            }
        }
        get_ans(n+m, 1, n, dis1);
        get_ans(n+m, n, 1, dis2);
        printf("Case #%d: ", ++ cas);
        if (dis1[n] == INF) {
            printf("Evil John\n");
            continue;
        }
        ll dis = INF;
        ans.clear();
        for (int i=1; i<=n; i++) {
            if (max(dis1[i], dis2[i]) == dis) {
                ans.push_back(i);
            }
            else{
                if (max(dis1[i], dis2[i]) < dis) {
                    ans.clear();
                    ans.push_back(i);
                    dis = max(dis1[i], dis2[i]);
                }
            }
        }
        cout<<dis/2<<"\n";
        for (int i=0; i<ans.size(); i++) {
            cout<<ans[i]<<(i==ans.size()-1?"\n":" ");
        }
    }
}
