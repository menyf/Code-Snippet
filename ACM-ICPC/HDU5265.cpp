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
ll a[maxn]={-1},p;
int n;
int main(){
	while (scanf("%d%lld",&n, &p)!=EOF) {
		for (int i = 1;i<=n;i++) {
			scanf("%lld",&a[i]);
			a[i] %= p;
		}
		sort(a+1, a+1+n);
		
		ll ans = 0, tmp, pos;
		for (int i = 1; i<=n; i++) {
			if (a[i] == a[i-1]) continue;
			tmp = p - a[i-1] - 1;
			pos = upper_bound(a+1, a+1+n, tmp) - a - 1;
			if (pos != n + 1) {
				if (pos != i) {
					ans = max(ans, (a[i] + a[pos])%p);
				}
			}
			
			tmp = 2*p - a[i-1] - 1;
			pos = upper_bound(a+1, a+1+n, tmp) - a - 1;
			if (pos != n + 1) {
				if (pos != i) {
					ans = max(ans, (a[i] + a[pos])%p);
				}
			}
		}
		
		cout<<ans<<"\n";
	}
}