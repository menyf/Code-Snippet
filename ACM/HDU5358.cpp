// Wrote by MenYifan on 2016-04-15 15:04:41
// Exe.Time 1918ms Exe.Memory 30528K
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 100005

long long arr[maxn];
long long rec[maxn][36];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		arr[n] = 0;

		for(int i=0;i<n;i++) {
			scanf("%I64d",arr+i);
		}

		for(int i=0;i<=34;i++) {
			long long mark = 1;
			mark<<=i+1;
			long long sum = arr[0];
			int k = 0;

			for(int j=0;j<n;j++) {
				if(j!=0)sum-=arr[j-1];

				while(sum<mark&&k<n) {
					sum+=arr[++k];
				}

				rec[j][i] = k;
			}

		}

		long long ans = 0;

		for(long long i=0;i<n;i++) {
			long long p = i;
			for(long long j=0;j<=34;j++) {
				long long k = rec[i][j];
				long long res;
				res = (j+1)*((i+1)*(k-p)+(p+k+1)*(k-p)/2);
				ans+=res;
				p = k;
			}
		}

		printf("%I64d\n",ans);
	}
	return 0;
}
