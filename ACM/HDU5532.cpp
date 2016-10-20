// F - Almost Sorted Array
// Created by 门一凡 on 16/10/9.
#include <set>
#include <map>
#include <list>
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
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
int a[maxn],n;
int dp[maxn];
int LIS1(int a[], int n) {
	int len = 1;
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] >= dp[len]) {
			dp[++len]=a[i];
		}
		else{
			int pos = upper_bound(dp + 1, dp + len + 1, a[i]) - dp; //找到插入位置
			dp[pos] = a[i];
		}
	}
	return len;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(a, 0, sizeof(a));
		scanf("%d",&n);
		for (int i =1; i <= n ;i++) scanf("%d",&a[i]);
		int tmp1 = LIS1(a, n);
		reverse(a+1, a+1+n);
		int tmp2 = LIS1(a, n);
		if (tmp1 == n || tmp1 == n-1 || tmp2 == n || tmp2 == n-1) puts("YES");
		else puts("NO");
	}
}