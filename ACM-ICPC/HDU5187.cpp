// Wrote by MenYifan on 2016-09-02 20:17:14
// Exe.Time 15ms Exe.Memory 1576K
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
#define rt(n)       (i == n ? '\n' : ' ')
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
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
    ll n,p;
    while (scanf("%lld%lld",&n,&p)!=EOF) {
        if (n==1&&p!=1)
            printf("1\n");
        else
            printf("%lld\n",(pow_mod(2,n,p)-2+p)%p);
    }
}