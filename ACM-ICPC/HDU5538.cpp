// L - House Building
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
int mp[55][55];
int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		memset(mp, 0, sizeof(mp));
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n ; i++) {
			for (int j = 1; j <= m ; j++) {
				scanf("%d" ,&mp[i][j]);
			}
		}
		ll ans = 0;
		for (int i =1; i <= n + 1 ; i++) {
			for (int j = 1; j <= m + 1 ; j++) {
				if (mp[i][j] != 0) {
					ans ++;
				}
				ans += abs(mp[i][j] - mp[i-1][j]);
				ans += abs(mp[i][j] - mp[i][j-1]);
			}
		}
		cout<<ans<<"\n";
	}
}