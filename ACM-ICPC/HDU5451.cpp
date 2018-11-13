// Wrote by MenYifan on 2016-08-29 11:04:32
// Exe.Time 608ms Exe.Memory 1992K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
typedef long long mytype;
const int SZ=105;
long long mod=1000000007;
long long quickpow(long long a, long long b)
{
    if(b < 0) return 0;
    long long ret = 1;
    a %= mod;
    for (; b; b >>= 1, a = (a * a) % mod)
        if (b & 1)
            ret = (ret * a) % mod;
    return ret;
}
long long inv(long long a)
{
    return quickpow(a,mod-2);
}
struct mat
{
    int n,m;
    mytype a[SZ][SZ];
    
    //???? n?m?
    mat(int n=SZ,int m=SZ):n(n),m(m) {}
    
    // ???
    void init(); //??
    mat unit(); //??????????????
    
    // ????
    void in();
    void out();
    
    //????
    mytype *operator [](int n);
    mat operator +(const mat &b);
    mat operator -(const mat &b);
    mat operator *(const mat &b);
    mat operator *(const mytype &b);
    mat operator /(const mytype &b);
    mat operator !();   //?????
    
    //?????
    friend mat quickpow(mat a, mytype b);
};
void mat::init()
{
    memset(a,0,sizeof(a));
}
mat mat::unit()
{
    mat t(n,n);
    t.init();
    for (int i=0; i<n; i++)
        t.a[i][i]=1;
    return t;
}
void mat::in()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%lld",&a[i][j]);
}
void mat::out()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            printf("%lld%c",a[i][j]," \n"[j==m-1]);
}
mytype *mat::operator [](int n)
{
    return *(a+n);
}
mat mat::operator +(const mat &b)
{
    mat t(n,m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            t.a[i][j]=(a[i][j]+b.a[i][j]+mod)%mod;
    return t;
}
mat mat::operator -(const mat &b)
{
    mat t(n,m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            t.a[i][j]=(a[i][j]-b.a[i][j]+mod)%mod;
    return t;
}
mat mat::operator *(const mat &b)
{
    mat t(n,b.m);
    for(int i=0; i<n; i++)
        for(int j=0; j<b.m; j++)
        {
            t.a[i][j]=0;
            for(int k=0; k<m; k++)
                t.a[i][j]=(t.a[i][j]+(a[i][k]*b.a[k][j])%mod)%mod;
        }
    return t;
}
mat mat::operator *(const mytype &b)
{
    mat t(n,m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            t.a[i][j]=a[i][j]*b%mod;
    return t;
}
mat mat::operator /(const mytype &b)
{
    mat t(n,m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            t.a[i][j]=a[i][j]*inv(b)%mod;
    return t;
}
mat mat::operator !()
{
    mat t(m,n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            t.a[i][j]=a[j][i];
    return t;
}

mat quickpow(mat a, mytype b)
{
    if(b<0) return a.unit();
    mat ret=a.unit();
    for (; b; b>>=1,a=a*a)
        if (b&1)
            ret=ret*a;
    return ret;
}
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
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        ll ans = 0;
        ll n;
        scanf("%lld%lld",&n,&mod);
        ll MOD = (mod + 1)*(mod - 1);
        ll pow = pow_mod(2, n, MOD) + 1;
        mat mt(2,2);
        mt.a[0][0] = 5; mt.a[0][1] = 12;
        mt.a[1][0] = 2; mt.a[1][1] = 5;
        if (pow == 1)
            ans = 9;
        else{
            mt = quickpow(mt, pow - 1);
            ans = (2*(mt.a[0][0]*5%mod+mt.a[0][1]*2%mod)%mod+mod-1)%mod;
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
}