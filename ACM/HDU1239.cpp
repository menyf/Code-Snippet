// Wrote by MenYifan on 2015-04-07 22:25:28
// Exe.Time 15ms Exe.Memory 2104K
//
//  20150406b.cpp
//  Cfiles
//
//  Created by ??? on 15/4/7.
//  Copyright (c) 2015? ???. All rights reserved.
//  ???????big god

#include <stdio.h>
#include <iostream>
using namespace std;
#define  MAX 100000
long long int prime[MAX],normal[MAX];
int cnt=0;
void make_prime(){
    for (long long i=2; i<MAX; i++) {
        if (normal[i]==0) {
            cnt++;
            prime[cnt]=i;
            for (long long int j=i*i; j<MAX; j+=i) {
                normal[j]=1;
            }
        }
    }
}
int main(){
    make_prime();
    long long x,y;
    long long m,p,q;
    while (scanf("%lld %lld %lld",&m,&p,&q)&&m+p+q) {
        long long product=0;
        for (long long j=cnt; prime[j]>=2; j--) {
            for (long long i=j; prime[i]<MAX; i++) {
                if (prime[j]*prime[i]>m||(double)prime[j]/prime[i]<(double)p/q) {
                    break;
                }
                if (prime[i]*prime[j]>product) {
                    x=prime[j];
                    y=prime[i];
                    product=x*y;
                }
            }
        }
        cout<<x<<" "<<y<<endl;
    }
}