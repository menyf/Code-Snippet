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
const int maxn=1000+5;
ll a[maxn];
ll dp[maxn]= {};
int n,p;
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&p);
		for (int i = 1; i <= n;i++) {
			scanf("%lld",&a[i]);
		}
		ll ans = -INF;
		dp[0] = -1;
		for (int j = 1 ;j <= n; j++) {
			int tmp = a[j];
			a[j] = p;
			for (int i=1; i<=n; i++)
			{
				 if (dp[i-1]<0)
				 {
					  dp[i]=a[i];
				 }
				 else
				 {
					  dp[i]=dp[i-1]+a[i];
				 }
			}
			ll mx=-INF;
			for (int i=1; i<=n; i++)
				 if (dp[i]>mx)
				 {
					  mx=dp[i];
				 }
			ans = max(ans, mx);
			a[j] = tmp;
		}
		cout<<ans<<"\n";
	}
}