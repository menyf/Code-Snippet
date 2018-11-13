// Wrote by MenYifan on 2016-03-24 08:03:16
// Exe.Time 31ms Exe.Memory 1624K
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
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (j == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 1000000+5
#define mod 1000000007
vector<int> v[105];
int vis[105];
int n,k,cnt=0,cnt1=0;
int dfs(int pos)
{
    int sz=v[pos].size();
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        int now=v[pos][i];
        ans+=1+dfs(now);
    }
    if(ans==k) cnt++;
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        cnt1=0;
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
        }
        int u,x;
        for(int i=1;i<n;i++)
        {
            cin>>u>>x;
            v[u].push_back(x);
            vis[x]=1;
        }
        int rt;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                rt=i;
        }
        dfs(rt);
        cout<<cnt<<endl;
    }
}