// Wrote by MenYifan on 2016-04-28 15:23:47
// Exe.Time 265ms Exe.Memory 1948K
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define mod 258280327
#define maxn 100005

int arr[maxn];
int dp[10];
int tdp[10];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		memset(dp,0,sizeof(dp));
		int n,a,b;
		dp[0] = 1;
		scanf("%d%d%d",&n,&a,&b);
		for(int i=0;i<n;i++) {
			scanf("%d",arr+i);
			for(int j = 0;j<=8;j++) {
				tdp[j] = dp[j];
			}

			for(int j = 0;j<=8;j++) {
				int tmp = (j+arr[i])%9;
				dp[tmp] += tdp[j];
				dp[tmp]%=mod;
			}

		}
		printf("%d\n",min(dp[a%9],dp[b%9]));
	}
	return 0;
}