// Wrote by MenYifan on 2015-04-06 19:12:40
// Exe.Time 234ms Exe.Memory 9716K
//
//  20150406a.cpp
//  Cfiles
//
//  Created by ??? on 15/4/6.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 1000050
int normal[MAX],prime[MAX],rPrime[MAX];
void make_prime(){
    prime[0]=1;
    rPrime[1]=0;
    int cnt=1;
    for (int i=2; i<MAX; i++) {
        if (!normal[i]) {
            prime[cnt]=i;
            rPrime[i]=cnt;
       //     printf("%d:%d\n",cnt,i);
            cnt++;
            for (int j=i; j<MAX; j+=i) {
                normal[j]=i;
            }
        }
    }
    return;
}
int main(){
    make_prime();
    int n;
    while (scanf("%d",&n)!=EOF) {
        printf("%d\n",rPrime[normal[n]]);
    }
}