// Wrote by MenYifan on 2016-08-25 13:19:48
// Exe.Time 78ms Exe.Memory 2860K
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

const int fcnt=120005;
LL fac[fcnt];
LL inv[fcnt];
LL powMod(LL a, LL b,LL mod){
    LL ans =1;
    for( a%=mod; b; b>>=1, a = a * a % mod)
        if(b&1)  ans = ans * a % mod;
    return  ans;
}

void init(LL mod) {
    fac[0] = 1;
    for(int i = 1; i < mod; i++)
        fac[i] = fac[i-1] * i % mod;
    inv[mod - 1]=powMod( fac[mod - 1], mod - 2, mod);
    for(int i = mod-2; i >= 0 ; i--)
        inv[i] = inv[i+1] * (i+1) % mod;
}

LL C(LL n, LL m,LL mod){
    return  m > n ? 0 : fac[n] * inv[m] % mod * inv[n-m] % mod;
}

LL Lucas(LL n, LL m,LL mod){// n>m
    if(n<0||m<0||n<m) return 0;
    return  m ? (C(n%mod , m%mod, mod) * Lucas(n/mod, m/mod, mod)) % mod : 1;
}

LL Q_mul(LL a, LL b,LL M)
{
    LL ret = 0;
    for (; b; b >>= 1, a = (a << 1) % M)
        if (b & 1)
            ret = (ret + a) % M;
    return ret;
}

LL ex_gcd(LL a,LL b,LL &x,LL &y){
    if (b==0) {
        x=1,y=0;
        return a;
    }
    else{
        LL res=ex_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return res;
    }
}

// ?????? ?????? x%(divisor[i])=rest[i]
LL CRT1(LL divisor[],LL rest[], int n){    //n???n????0~n-1
    LL gcd,tmp,product=1,res=0,x,y;
    for (int i=0; i<n; i++)
        product*=divisor[i];
    for (int i=0; i<n; i++) {
        tmp=product/divisor[i];
        gcd=ex_gcd(divisor[i], tmp, x, y);
        res=(res+Q_mul(Q_mul(y,tmp,product),rest[i],product))%product;
    }
    return (res + product) % product;//????????????
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		LL n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		LL p[15],r[15];
		for(LL i=0; i<k; i++) {
			scanf("%lld",&p[i]);
			//printf("p[%lld]: %lld ",i,p[i]);
			init(p[i]);
			r[i] = Lucas(n,m,p[i]);
			//printf("r[%lld]: %lld\n",i,r[i]);
		}
		LL ans = CRT1(p,r,k);
		printf("%lld\n",ans);
	}
	return 0;
}