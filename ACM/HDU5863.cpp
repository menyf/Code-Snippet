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
const int maxn=200000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
typedef long long mytype;
const int SZ=15;
struct mat
{
    int n,m;
    mytype a[SZ][SZ];
    mat(){}
    mat (int sz,int k);
    void init(); //清零
    mat unit(); //该函数的返回值为一个单位矩阵
    mat operator *(const mat &b);
    friend mat quickpow(mat a, mytype b);
};
mat::mat(int sz,int k){
    Memset(a, 0);
    n = m = sz;
    for(int i=0;i<sz;i++){
        a[i][0] = k*k - k;
        if(i<sz-1){
            a[i][i+1] = k;
        }
    }
}
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
    int n,m,k;
    int T;
    scanf("%d",&T);
    while (T--) {
        cin>>n>>m>>k;
        mat b(m+1, k);
        mat c(m, k);
        
        b = quickpow(b, n);
        c = quickpow(c, n);
        
        ll ans = 0;
        for (int i=0; i<b.m; i++)
            ans = (ans + b.a[0][i]) % mod;
        
        for (int i=0; i<c.m; i++)
            ans = (ans + mod - c.a[0][i])%mod;
        
        cout<<( ans + mod ) % mod<<endl;
    }
    return 0;
}


