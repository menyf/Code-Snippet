// Wrote by MenYifan on 2016-09-03 12:51:57
// Exe.Time 31ms Exe.Memory 1960K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int num[maxn]={};
ll dp[maxn][2];
int main(){
    int n,tmp;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&tmp);
        num[tmp]++;
    }
    ll ans = 0;
    for (int i=1; i<=100000; i++) {
        dp[i][1] = max(dp[i-1][0] + (ll) i*num[i], dp[i][1]);
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        ans = max(ans, dp[i][1]);
        ans = max(ans, dp[i][0]);
    }
    cout<<ans<<endl;
}