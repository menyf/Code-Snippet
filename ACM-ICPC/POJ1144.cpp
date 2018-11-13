// Wrote by MenYifan on 2016-09-05 18:53:03
// Exe.Time 47ms Exe.Memory 720K
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
const double eps=1e-8;

//?????????
const int maxn=100+10;
int n,m;//n?? m?? ????0~n-1
int dfs_clock;//???????????1
vector<int> G[maxn];//G[i]??i?????????
int pre[maxn];//pre[i]??i?????????????,?pre[i]==0??i?????
int low[maxn];//low[i]??i?????????????????????pre?
bool iscut[maxn];//??i?????????
vector<pair<int, int> >Bridge;
int ans;
int dfs(int u,int fa=-1)//???u????(u?DFS???????fa)?????????
{
    int lowu=pre[u]=++dfs_clock;
    int child=0;    //?????
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!pre[v]){
            child++;//???????????u???
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u]){
                iscut[u]=true;      //u????
                if(lowv>pre[u]) //????
                    Bridge.push_back(make_pair(u, v));
            }
        }
        else if(pre[v]<pre[u] && v!=fa){//v!=fa???(u,v)??u?v????
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0 && child==1 )
        iscut[u]=false;//u???????<=1,?u?????
    return low[u]=lowu;
}
int main(){
    // input & initialize
    while (scanf("%d",&n),n) {
        dfs_clock=0;//?????
        memset(pre,0,sizeof(pre));
        memset(iscut,0,sizeof(iscut));
        Bridge.clear();
        for(int i=0;i<n;i++) G[i].clear();
        ans = 0;
        char ch;
        int u,v;
        while (cin>>u&&u) {
            while (getchar()!='\n') {
                scanf("%d",&v);
                G[u-1].push_back(v-1);
                G[v-1].push_back(u-1);
                if (ch == '\n') break;
            }
        }
        int root = 0;
        dfs(root);//??dfs????
        for(int i=0;i<n;i++)
            if(iscut[i]==true)
                ans++;
        cout<<ans<<'\n';
    }
}