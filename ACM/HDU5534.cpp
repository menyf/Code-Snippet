//
// Untitled 4.cpp
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
const int maxn=2015+5;
int f[maxn];
int dp[maxn];
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n - 1 ; i++) {
			scanf("%d",&f[i]);
			if (i) f[i] -= f[0];
		}
		memset(dp, -INF, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i < n - 1 ; i++) {
			for (int j = i; j <= n - 2; j++) {
				dp[j] = max(dp[j], dp[j-i] + f[i]);
			}
		}
		ll ans = n*f[0]+dp[n-2];
		printf("%lld\n",ans);
	}
}