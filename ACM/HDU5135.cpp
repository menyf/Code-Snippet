// Wrote by MenYifan on 2016-09-28 19:06:48
// Exe.Time 31ms Exe.Memory 1632K
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
double a[35];
double dp[1<<13];
double ha(double a, double b, double c){
	double p = (a+b+c)/2;
	double s = sqrt(p * (p-a)*(p-b)*(p-c));
	return s;
}
bool check(double a, double b, double c){
	if ( (b+c) - a <= eps  ) {
		return false;
	}
	if ((a+c) - b<= eps) {
		return false;
	}
	if ((b+a) - c<= eps) {
		return false;
	}
	return true;
}
int main(){
	int n;
	while (scanf("%d",&n),n) {
		for ( int i = 0; i < n;i++) {
			scanf("%lf",&a[i]);
//			debug(a[i]);
		}
		for (int i = 0 ;i < (1 << n);i++) {
			dp[i] = 0;
		}
		double ans = 0;
		for (int i = 0;i < n ;i ++) {
			for (int j = i+1 ;j<n;j++) {
				for (int k = j+1;k<n;k++) {
					for (int z = 0 ;z < (1<<n);z++) {
						int tmp = z + (1<<i) + (1 << j) + (1 << k);
						if (check(a[i], a[j], a[k]) && (((z>>i)&1) == 0) && ((z>>j)&1) == 0 && ((z >>k) & 1) == 0) {
//							hi;
							dp[tmp] = dp[z] + ha(a[i], a[j], a[k]);
							ans = max(ans, dp[tmp]);
						}
					}
				}
			}
		}
		printf("%.2f\n",ans);
	}
}