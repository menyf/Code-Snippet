//G. UmBasketella
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
const int mod=10007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
ll mult_mod(ll a,ll b,ll mod){
	return (a*b-(ll)(a/(long double)mod*b+1e-3)*mod+mod)%mod;
}
ll pow_mod(ll x, ll n, ll mod) { //x^n%c
	if(n == 1)return x % mod;
	x %= mod;
	ll tmp = x;
	ll ret = 1;
	while(n) {
		if(n & 1) ret = mult_mod(ret, tmp, mod);
		tmp = mult_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		ll tmp = pow_mod(2, n-1, mod);
		ll ans = (tmp * tmp % mod + tmp)%mod;
		printf("%lld\n",ans);
	}
}