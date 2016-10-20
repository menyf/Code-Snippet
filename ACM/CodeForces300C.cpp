// Wrote by MenYifan on 2016-09-29 23:16:20
// Exe.Time 998ms Exe.Memory 15664K
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
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
const int maxn=1e6+5;
ll n,a,b;
ll fac[maxn],ni[maxn];
ll quickpow(ll a, ll b) {
	if (b < 0) return 0;
	ll ret = 1;
	a %= mod;
	while(b) {
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}
ll inv(ll a) {
	return quickpow(a, mod - 2);
}
void getfac()
{
	fac[0]=1;
	for (int i=1; i<=n; i++){
		fac[i]=fac[i-1]*i%mod;
		ni[i] = inv(fac[i]);
	}
}
ll C(ll n,ll m)
{
	if (m==0 || n == m) 
		return 1;
	if (n<m)
		return 0;
	return fac[n]*ni[m]%mod*ni[n-m]%mod;
}
bool check(int num){
	while (num) {
		int tmp = num % 10;
		if (tmp != a && tmp != b) {
			return false;
		}
		num /= 10;
	}
	return true;
}
int main(){
	cin>>a>>b>>n;
	getfac();
	ll ans = 0;
	for (int i = 0 ; i <= n ; i++) {
		int j = n - i;
		int sum = a * i + b * j;
		if (check(sum)) {
			ans += C(n, i) % mod;
		}
	}
	printf("%lld\n",ans%mod);
}