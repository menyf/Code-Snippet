#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
typedef long long mytype;
const int SZ=105;
long long M=1000000007;
long long quickpow(long long a, long long b)
{
    if(b < 0) return 0;
    long long ret = 1;
    a %= M;
    for (; b; b >>= 1, a = (a * a) % M)
        if (b & 1)
            ret = (ret * a) % M;
    return ret;
}
long long inv(long long a)
{
    return quickpow(a,M-2);
}
struct mat
{
    int n,m;
    mytype a[SZ][SZ];
    void init()
    {
        memset(a,0,sizeof(a));
    }
    mat(int n=SZ,int m=SZ):n(n),m(m) {}
    mat unit()
    {
        mat t(n,n);
        t.init();
        for (int i=0; i<n; i++)
            t.a[i][i]=1;
        return t;
    }
    mytype *operator [](int n)
    {
        return *(a+n);
    }
    mat operator +(const mat &b)
    {
        mat t(n,m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                t.a[i][j]=(a[i][j]+b.a[i][j]+M)%M;
        return t;
    }
    mat operator -(const mat &b)
    {
        mat t(n,m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                t.a[i][j]=(a[i][j]-b.a[i][j]+M)%M;
        return t;
    }
    mat operator *(const mat &b)
    {
        mat t(n,b.m);
        for(int i=0; i<n; i++)
            for(int j=0; j<b.m; j++)
            {
                t.a[i][j]=0;
                for(int k=0; k<m; k++)
                    t.a[i][j]=(t.a[i][j]+(a[i][k]*b.a[k][j])%M)%M;
            }
        return t;
    }
    mat operator *(const mytype &b)
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t.a[i][j]=a[i][j]*b%M;
        return t;
    }
    mat operator /(const mytype &b)
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t.a[i][j]=a[i][j]*inv(b)%M;
        return t;
    }
    mat operator !()
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t.a[i][j]=a[j][i];
        return t;
    }
    friend mat quickpow(mat a, mytype b)
    {
        if(b<0) return a.unit();
        mat ret=a.unit();
        for (; b; b>>=1,a=a*a)
            if (b&1)
                ret=ret*a;
        return ret;
    }
    void in()
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%lld",&a[i][j]);
    }
    void out()
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                printf("%lld%c",a[i][j]," \n"[j==m-1]);
    }
};

ll euler(ll x) {
    ll res = x;
    for (ll i = 2; i <= x / i; i++) if (x % i == 0) {
        res = res / i * (i - 1);
        while(x % i == 0) x /= i;
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
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
    int t;
    ll n,a,b,c,p;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&p);
        M=euler(p);
        mat m=mat(3,3);
        mat tmp=mat(3,3);
        m.a[0][0]=0;m.a[0][1]=1;m.a[0][2]=0;
        m.a[1][0]=1;m.a[1][1]=c;m.a[1][2]=1;
        m.a[2][0]=0;m.a[2][1]=0;m.a[2][2]=1;
        tmp=quickpow(m,n-2);
        mat o=mat(3,1);
        o.a[0][0]=0;
        o.a[1][0]=b;
        o.a[2][0]=b;
        mat ans=tmp*o;
        cout<<pow_mod(a, ans.a[1][0]+M, p)<<endl;
    }
}
