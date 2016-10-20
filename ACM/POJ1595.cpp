// Wrote by MenYifan on 2015-03-21 17:31:34
// Exe.Time 0ms Exe.Memory 364K
//
//  20150320g.cpp
//  Cfiles
//
//  Created by ??? on 15/3/21.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
using namespace std;
int prime[200],normal[1050],rPrime[1050];
void isprime(){
    prime[0]=1;
    //prime[1]=2;
    int cnt=0;
    for (int i=2; i<1050; i++) {
        if (!normal[i]) {
            prime[++cnt]=i;
            rPrime[i]=cnt;
            normal[i]=i;
            for (int k=i*i; k<1050; k+=i) {
                normal[k]=1;
            }
        }
    }
}
int main(){
    isprime();
    int n,c,prime_end;
    while (scanf("%d%d",&n,&c)!=EOF) {
        printf("%d %d:",n,c);
        
        //?????????????rPrime(prime_end)
        for (int i=n;i>=0 ; i--) {
            if (normal[i]==i) {
                prime_end=i;
                break;
            }
        }
        
        if (rPrime[prime_end]%2==1) {
            //???
            if (2*c>=rPrime[prime_end]+1) {
                //????
                for (int i=0; i<=rPrime[prime_end]; i++) {
                    printf(" %d",prime[i]);
                }
            }
            else{
                //????
                for (int i=0; i<2*c; i++) {
                    printf(" %d",prime[(rPrime[prime_end]+1-2*c)/2-1+i+1]);
                }
            }
        }
        else{
            //???
            if (2*c-1>=rPrime[prime_end]+1) {
                //????
                for (int i=0; i<=rPrime[prime_end]; i++) {
                    printf(" %d",prime[i]);
                }
            }
            else{
                //????
                for (int i=0; i<2*c-1; i++) {
                    printf(" %d",prime[rPrime[prime_end]/2-c+i+1]);
                }
            }
        }
        printf("\n\n");
    }
}