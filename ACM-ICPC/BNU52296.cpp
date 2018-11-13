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
int x[3],y[3],z[3];
int main(){
	for (int i = 0; i < 3 ; i++) {
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	ll ans = 0;
	if (x[0] < x[1] || x[0] > x[2] ) {
		int tmp = min(abs(x[0]-x[1]), abs(x[0]-x[2]));
		ans += (ll) tmp * tmp;
	}
	if (y[0] < y[1] || y[0] > y[2] ) {
		int tmp = min(abs(y[0]-y[1]), abs(y[0]-y[2]));
		ans += (ll) tmp * tmp;
	}
	if (z[0] < z[1] || z[0] > z[2] ) {
		int tmp = min(abs(z[0]-z[1]), abs(z[0]-z[2]));
		ans += (ll) tmp * tmp;
	}
	cout<<ans<<"\n";
}