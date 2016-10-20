// Wrote by MenYifan on 2015-03-22 09:30:13
// Exe.Time 15ms Exe.Memory 87K
//
//  20150320c.cpp
//  Cfiles
//
//  Created by ??? on 15/3/20.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include<iostream>


long long int qPow(long long int A,long long int n,long long mod)
{
    //?a^n%mod???
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
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int num,cnt=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&num);
        if (qPow(num, m,k)==0) {
            cnt++;
        }
    }
    printf("%d",cnt);
}