// Wrote by MenYifan on 2016-05-09 18:30:30
// Exe.Time 1550ms Exe.Memory 77604K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
#define inf 9999
#define Vmax 1000005
#define Emax 4000005
int pre[Vmax],ecnt;
struct edge{
    int v,w,next;
}e[Emax*2];
int dis[Vmax];
int vcnt[Vmax];//????????????????????
bool inq[Vmax];
void init(){
    ecnt=0;
    memset(vcnt,0,sizeof(vcnt));
    memset(pre,-1,sizeof(pre));
    memset(inq, false, sizeof(inq));
}
//***??????
void adde(int from,int to,int w){
    
    //??
    for (int i=pre[from]; i!=-1; i=e[i].next) {
        if (e[i].v==to) {
            e[i].w=min(e[i].w, w);
            return;
        }
    }
    
    e[ecnt].v=to;
    e[ecnt].w=w;
    e[ecnt].next=pre[from];
    pre[from]=ecnt++;
}
bool SPFA(int n,int source){//n???? source???
    //return true??????????
    for (int i=0; i<=n; i++)
        dis[i]=inf;
    dis[source]=0;
    queue<int>q;
    q.push(source);inq[source]=true;
    
    while (!q.empty()) {
        int tmp=q.front();
        q.pop();inq[tmp]=false;
        
        //????
        vcnt[tmp]++;
        if (vcnt[tmp]>=n) return false;
        
        for (int i=pre[tmp]; i!=-1; i=e[i].next) {
            int w=e[i].w;
            int v=e[i].v;
            if (dis[tmp]+w<dis[v]) {
                dis[v]=dis[tmp]+w;  //????
                if (!inq[v]) {
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return true;
}
int get_ans(int n,int source,int destination){
    SPFA(n,source);
    return dis[destination];
}
void buildGraph(int N, int Seed) {
    int nextRand = Seed;
    // initialize random number generator
    for (int x = 1; x <= N; x++) {
        // generate edges from Node x
        int w = x % 10 + 1;            // the weight of edges
        int d = 10 - w;                // the number of edges
        for (int i = 1; i <= d; i++) {
            adde(x, nextRand % N + 1, w);
            // add a new edge into G
            nextRand = nextRand * 233 % N;
        }
        adde(x, x % N + 1, w);
    }
}
int main(){
    int t,n,s;
    cin>>t;
    while (t--) {
        cin>>n>>s;
        init();
        buildGraph(n, s);
        cout<<get_ans(n,1,n)<<endl;
    }
    return 0;
}
