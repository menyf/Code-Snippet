// Wrote by MenYifan on 2015-04-06 19:21:46
// Exe.Time 0ms Exe.Memory 1580K
#include <stdio.h>
#include <iostream>
using namespace std;
long long int qPow(long long int A,long long int n,long long mod)
{
    //?a^n
    if (n == 0) return 1;
    long long int rslt = 1;
    
    while (n)
    {
        if (n & 1)
        {
            rslt =rslt*A%mod;
        }
        A = A*A%mod;
        n >>= 1;
    }
    return rslt;
}

int main(){
    long long int n;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld",&n);
        printf("%lld\n",qPow(n,n,10));
    }
}