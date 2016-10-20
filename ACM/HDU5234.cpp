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
#define fre() freopen("data_in.txt","r",stdin); \
			  freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
int n, m, kk;
int mp[105][105];
int dp[105][105][105];
int main(){
	while (scanf("%d%d%d",&n,&m,&kk)!=EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m;j++) {
				scanf("%d",&mp[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[1][1][0] = 1;
		dp[1][1][mp[1][1]] = 1;
		for (int i = 1; i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				for (int k = 0;k <= kk; k++) {
					dp[i][j][k] |= dp[i-1][j][k];
					dp[i][j][k] |= dp[i][j-1][k];
					if (k >= mp[i][j]) {
						dp[i][j][k] |= dp[i-1][j][k-mp[i][j]];
						dp[i][j][k] |= dp[i][j-1][k-mp[i][j]];
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0;i<=kk;i++) {
			if (dp[n][m][i]) {
				ans = i;
			}
		}
		cout<<ans<<"\n";
	}
}