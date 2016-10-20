// Wrote by MenYifan on 2015-04-06 19:43:20
// Exe.Time 30ms Exe.Memory 4K
//
//  20150406h.cpp
//  Cfiles
//
//  Created by ??? on 15/4/6.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    long long a,b,c;
    scanf("%lld %lld",&a,&b);
    long long int cnt=0;
    while (a!=b&&a!=0) {
        if (a<b) {
            long long temp;
            temp=a;
            a=b;
            b=temp;
        }
        c=a%b;
        cnt+=a/b;
        a=c;
    }
    printf("%lld\n",cnt);
}