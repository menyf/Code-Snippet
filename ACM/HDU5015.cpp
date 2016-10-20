// Wrote by MenYifan on 2015-11-10 18:55:07
// Exe.Time 873ms Exe.Memory 1584K
//
//  20151108g.cpp
//  Cfiles
//
//  Created by ??? on 15/11/10.
//  Copyright   2015? ???. All rights reserved.
//

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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
#define mod 10000007
typedef long long mytype;
const int SZ=15;

const long long M=10000007;
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
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
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
                printf("%2lld%c",a[i][j]," \n"[j==m-1]);
    }
};
int main(){
    int n;
    ll m;
    while (scanf("%d %lld",&n,&m)!=EOF) {
        mat uni(n+2,n+2);
        uni.init();
        for (int i=0; i<n+2; i++) {
            for (int j=0; j<n+2; j++) {
                if (i!=n+1&&j==0) {
                    uni.a[i][j]=10;
                }
                else if (j==n+1){
                    uni.a[i][j]=1;
                }
                else if (i!=n+1&&j<=i){
                    uni.a[i][j]=1;
                }
            }
        }
        //uni.out();
        uni=quickpow(uni, m);
        
        mat a(n+2,1);
        a.init();
        a.a[0][0]=23;
        a.a[n+1][0]=3;
        
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a.a[i][0]);
        }
        
        a=uni*a;
//        a.out();
        cout<<a.a[n][0]%M<<endl;
    }
}
