// Wrote by MenYifan on 2016-08-20 20:03:28
// Exe.Time 78ms Exe.Memory 1984K
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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=10000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
typedef long long mytype;
const int SZ=10;
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
    mat quickpow(mat a, mytype b);
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

mat mat::quickpow(mat a, mytype b)
{
    if(b<0) return a.unit();
    mat ret=a.unit();
    for (; b; b>>=1,a=a*a)
        if (b&1)
            ret=ret*a;
    return ret;
}
int xx[3][3]={0,1,1,1,1,1,0,0,1};
int yy[maxn];
int main(){
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF) {
        ll sum = 0;
        ll mx = -1;
        ll mmx = -1;
        for (ll i=1; i<=n; i++) {
            scanf("%d",&yy[i]);
            sum += yy[i];
            sum %= mod;
        }
        sort(yy+1, yy+1+n);
        
        sum = (sum - yy[n] - yy[n-1]) % mod + mod ;
        sum %= mod;
        
        mmx = yy[n-1];
        mx = yy[n];
        
        mat m(3,3);
        for (ll i=0; i<3; i++) {
            for (ll j=0; j<3; j++) {
                m.a[i][j] = xx[i][j];
            }
        }
        
        m = m.quickpow(m, k);
        
        mat mm(1,3);
        mm.a[0][0] = mmx;
        mm.a[0][1] = mx;
        mm.a[0][2] = mmx+mx;
        
        mat ans = mm*m;
        
        sum += ans.a[0][2];
        cout<<(sum%mod+mod)%mod<<endl;
    }
}