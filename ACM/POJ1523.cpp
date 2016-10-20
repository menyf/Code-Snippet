// Wrote by MenYifan on 2016-09-05 23:00:43
// Exe.Time 0ms Exe.Memory 2724K
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
const int maxn=100000+10;    //???
int n,m;//n?? m?? ????0~n-1
int dfs_clock;//???????????1
vector<int> G[maxn];//G[i]??i?????????
int pre[maxn];//pre[i]??i?????????????,?pre[i]==0??i?????
int low[maxn];//low[i]??i?????????????????????pre?
bool iscut[maxn];//??i?????????
int cut[maxn];//cut[i]???i?????????????
vector<pair<int, int> >Bridge;

int dfs(int u,int fa=-1)//???u????(u?DFS???????fa)?????????
{
    if (fa == -1) cut[u]--; //???????????????????????
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
                cut[u]++;
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
    int u,v,cas=1;
    n = 1000;
    while (scanf("%d",&u),u) {
        for(int i=0;i<n;i++) G[i].clear();
        dfs_clock=0;//?????
        memset(pre,0,sizeof(pre));
        memset(cut, 0, sizeof(cut));
        memset(iscut,0,sizeof(iscut));
        Bridge.clear();
        
        scanf("%d",&v);
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);

        int mx=max(u, v);
        while (scanf("%d",&u),u) {
            scanf("%d",&v);
            mx = max(mx, u);
            mx = max(mx, v);
            G[u-1].push_back(v-1);
            G[v-1].push_back(u-1);
        }

        //Apllication
        int k = 0;
        for (int i=0; i<mx; i++) {
            if (G[i].size()!=0&&!pre[i]) {
                k++;
                dfs(i);//?????????
            }
        }
        
        if (cas!=1) {
            printf("\n");
        }
        printf("Network #%d\n",cas++);
        bool flag = false;
        for (int i=0; i<mx; i++) {
            if (cut[i] > 0) {
                flag = true;
                printf("  SPF node %d leaves %d subnets\n",i+1,k+cut[i]);
            }
        }
        if (!flag) printf("  No SPF nodes\n");
    }
}