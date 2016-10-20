// Wrote by MenYifan on 2016-08-31 13:14:02
// Exe.Time 0ms Exe.Memory 984K
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
ll dp[15][15][2];
int num[15];
ll dfs(int pos,int pre,bool limit,bool first){
    if (pos < 1) {
        return 1;
    }
    if (!limit&&dp[pos][pre][first]!=-1) {
        return dp[pos][pre][first];
    }
    int mx = limit?num[pos]:9;
    ll ret = 0;
    for (int i=0; i<=mx; i++) {
        if (first||i-pre>=2||pre-i>=2){
            ret += dfs(pos-1, i, limit&&i==mx,first&&i==0);
        }
    }
    if (!limit) {
        dp[pos][pre][first] = ret;
    }
    return ret;
}
ll solve(ll x){
    Memset(dp, -1);
    int pos = 0;
    while (x!=0) {
        num[++pos] = x % 10;
        x/=10;
    }
    ll ans = dfs(pos, 0, 1, 1);
    return ans;
}
int main(){
    ll a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF) {
        cout<<solve(b) - solve(a-1)<<endl;
    }
}