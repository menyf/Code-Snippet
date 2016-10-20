// Wrote by MenYifan on 2015-03-28 00:01:10
// Exe.Time 94ms Exe.Memory 11364K
//
//  20150327d.cpp
//  Cfiles
//
//  Created by ??? on 15/3/27.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#define NUM 1299709+5
long long int prime[100050],normal[NUM],cnt=0;
void isPrime(){
    prime[cnt++]=2;
    for (long long i=3; i<NUM; i+=2) {
        if (normal[i]==0) {
            prime[++cnt]=i;
        //    prlong longf("%d %d\n",cnt,prime[cnt]);
            for (long long j=i*i; j<NUM; j+=i) {
                normal[j]=1;
            }
        }
    }
}
long long gap(long long n){
    long long l=1,r=cnt,mid;
    if (n==2) {
        return 0;
    }
    while (l<=r) {
        mid=(l+r)/2;
        if (prime[mid]>n) {
            r=mid-1;
        }
        else if(prime[mid]<n)
            l=mid+1;
        else
            return 0;
    }
    return prime[l]-prime[r];
}

int main(){
    isPrime();
    long long int num;
    scanf("%lld",&num);
    while (num!=0) {
        printf("%lld\n",gap(num));
        scanf("%lld",&num);
    }
}