// Wrote by MenYifan on 2015-03-22 09:26:00
// Exe.Time 94ms Exe.Memory 352K
//
//  20150320i.cpp
//  Cfiles
//
//  Created by ??? on 15/3/21.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <string.h>
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
    int t;
    scanf("%d",&t);
    int m,h,a,b,ans;
    for (int j=0; j<t; j++) {
        ans=0;
      //  memset(a, 0, sizeof(a));
      //  memset(b, 0, sizeof(b));
        scanf("%d%d",&m,&h);
        for (int i=0; i<h; i++) {
            scanf("%d%d",&a,&b);
            ans=(ans%m+qPow(a, b,m))%m;
        }
        printf("%d\n",ans);
    }
}