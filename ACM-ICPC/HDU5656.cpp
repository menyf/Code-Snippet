// Wrote by MenYifan on 2016-04-04 20:28:04
// Exe.Time 2527ms Exe.Memory 9480K
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define mod 100000007
long long dp[1005][1005];
long long arr[1005];

long long gcd(long long a,long long b) {
	return b==0?a:gcd(b,a%b);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%I64d",&arr[i]);
		}
		dp[0][0] = 1;

		for(int i=0;i<n;i++) {
			for(int j = 0;j<1005;j++) {
				if(dp[i][j]) {
					(dp[i+1][j] += dp[i][j])%=mod;
					(dp[i+1][gcd(j,arr[i+1])] +=dp[i][j])%=mod;
				}
			}
		}

		long long ans = 0;

		for(long long i=1;i<=1005;i++) {ans+=dp[n][i]*i,ans%=mod;}
		printf("%I64d\n",ans);
	}
	return 0;
}