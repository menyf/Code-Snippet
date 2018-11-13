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
const int mod=1024;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int SZ=105;
typedef long long mytype;
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
    
    //构造函数 n行m列
    mat(int n=SZ,int m=SZ):n(n),m(m) {}
    
    // 初始化
    void init(); //清零
    mat unit(); //该函数的返回值为一个单位矩阵
    
    // 输入输出
    void in();
    void out();
    
    //基本运算
    mytype *operator [](int n);
    mat operator +(const mat &b);
    mat operator -(const mat &b);
    mat operator *(const mat &b);
    mat operator *(const mytype &b);
    mat operator /(const mytype &b);
    mat operator !();   //矩阵的转置
    
    //矩阵快速幂
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
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        mat m(2,2);
        m.a[0][0] = 5; m.a[0][1]=12;
        m.a[1][0] = 2; m.a[1][1]=5;
        int n;
        scanf("%d",&n);
        m = quickpow(m, n-1);
//        m.out();
        
        mat a(2,1);
        a.a[0][0] = 5; a.a[1][0] = 2;
        a = m * a;
//        a.out();
        ll ans = (2*a.a[0][0] -1)%mod ;
        cout<<ans<<"\n";
    }
}
