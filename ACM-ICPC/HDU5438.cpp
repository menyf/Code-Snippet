// Wrote by MenYifan on 2016-05-18 21:34:11
// Exe.Time 124ms Exe.Memory 3560K
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
typedef long long ll;
using namespace std;
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
set<int>st[maxn];
int v[maxn],vis[maxn];
void dfs(int x){
    int v=*st[x].begin();
    st[x].clear();
    st[v].erase(x);
    if (st[v].size()==1) {
        dfs(v);
    }
}
ll bfs(int x){
    ll ans=0;
    int step=0;
    vis[x]=1;
    queue<int>q;
    q.push(x);
    while (!q.empty()) {
        step++;
        int now=q.front();
        ans+=v[now];
        q.pop();
        for (auto it = st[now].begin(); it!=st[now].end(); it++) {
            if (!vis[*it]) {
                q.push(*it);
                vis[*it]=1;
            }
        }
    }
    
    
    if (step%2)
        return ans;
    else
        return 0;
}
int main(){
    int t,n,m,x,y;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            scanf("%d",&v[i]);
            st[i].clear();
            vis[i]=0;
        }
        for (int i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            st[x].insert(y);
            st[y].insert(x);
        }
        for (int i=1; i<=n; i++) {
            if (st[i].size()==1) {
                dfs(i);
            }
        }
        ll ans=0;
        for (int i=1; i<=n; i++) {
            if (st[i].size()!=0&&vis[i]==0) {
                ans+=bfs(i);
            }
        }
        
        cout<<ans<<endl;
    }
}