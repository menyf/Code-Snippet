// Wrote by MenYifan on 2016-09-05 21:13:41
// Exe.Time 46ms Exe.Memory 9484K
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
const int maxn = 1e5 + 10;
vector<int>G[maxn];
int c[maxn];
ll dp[maxn][2];
void dfs(int u = 0){
    dp[u][0] = 1;
    dp[u][1] = 0;
    for (int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        dfs(v);
        dp[u][1] = (dp[u][0]*dp[v][1] + dp[u][1]*dp[v][0]) % mod;
        dp[u][0] = dp[u][0] * dp[v][0] % mod;
    }
    if (c[u]) {
        dp[u][1] = dp[u][0];
    }
    else{
        dp[u][0] = (dp[u][0] + dp[u][1]) % mod;
    }
}
int main(){
    int n,v;
    scanf("%d",&n);
    for (int i=1; i<n; i++) {
        scanf("%d",&v);
        G[v].push_back(i);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&c[i]);
    }
    dfs();
    cout<<dp[0][1]<<endl;
}