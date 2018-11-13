// Wrote by MenYifan on 2016-07-29 20:38:44
// Exe.Time 124ms Exe.Memory 2100K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=1000+50;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn];
vector<int> v[maxn];
int dfs(int x){
    if (v[x].size()==0) {
        return 0;
    }
    if (v[x].size()>1) {
        return 1;
    }
    return dfs(v[x][0]);
}
void work(){
    int n;
    int dp[maxn]={},vis[maxn]={},pre[maxn]={};
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        v[i].clear();
    }
    int len=0,mx=0,pos=-1,now;
    for (int i=1; i<=n; i++) {
        pre[i]=i;
        dp[i]=1;
        for (int j=i-1; j>=1; j--) {
            if (a[j]<a[i]&&dp[i]<dp[j]+1) {
                dp[i]=dp[j]+1;
                v[i].clear();
                v[i].push_back(j);
            }
            else if (a[j]<a[i]&&dp[i]==dp[j]+1){
                v[i].push_back(j);
            }
        }
        if (dp[i]>mx) {
            mx=dp[i];
            now=i;
            pos=-1;
        }
        else if (dp[i]==mx){
            pos=i;
        }
    }
    if (pos!=-1) {
        printf("%d\n",mx);
        return;
    }

    
    if (dfs(now))
        printf("%d\n",max(mx, 1));
    else
        printf("%d\n",max(mx-1, 1));
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        work();
    }
    return 0;
}

