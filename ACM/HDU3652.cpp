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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=30+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int dp[15][15][13][2];
int num[15];
int dfs(int pos,int pre,int mod,int status, bool limit){
    if (pos==0) {
        return mod==0&&status;
    }
    if (!limit&&dp[pos][pre][mod][status]!=-1) {
        return dp[pos][pre][mod][status];
    }
    int ret = 0;
    int mx = limit?num[pos]:9;
    for (int i=0; i<=mx; i++) {
        ret += dfs(pos-1, i, (mod*10+i)%13, status||(pre == 1 && i == 3), limit&&i==mx);
    }
    if (!limit) {
        dp[pos][pre][mod][status] = ret;
    }
    return ret;
}
int solve(int x){
    Memset(dp, -1);
    int pos = 0;
    while (x!=0) {
        num[++pos] = x % 10;
        x/=10;
    }
    return dfs(pos, 0, 0, 0, 1);
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        cout<<solve(n)<<endl;
    }
    return 0;
}
