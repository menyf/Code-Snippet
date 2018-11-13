//
// Untitled 4.cpp
// Created by 门一凡 on 16/10/12.
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
const int maxn=10000+5;
int dp[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int E, F, n;
		scanf("%d%d",&E,&F);
		int V = F - E;
		for (int i = 1; i <= V; i++)  dp[i] = -INF;
		scanf("%d", &n);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			int c,w;
			scanf("%d%d",&c,&w);
			c *= -1;
			for (int j = w; j <= V; j++) {
				dp[j] = max(dp[j], dp[j-w]+c);
			}
		}
		if (dp[V] == -INF) {
			printf("This is impossible.\n");
		}
		else {
			printf("The minimum amount of money in the piggy-bank is %d.\n",-dp[V]);
		}
	}
}