// Wrote by MenYifan on 2015-03-22 22:36:01
// Exe.Time 530ms Exe.Memory 3964K
//
//  20150322h.cpp
//  Cfiles
//
//  Created by ??? on 15/3/22.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include "algorithm"
#include <set>
#include "iostream"
using namespace std;
set<long long int> s1;
int main(){
    
    long long int n,k,cnt=0;
    scanf("%lld%lld",&n,&k);
    long long int num[n];
    for (long long int i=0; i<n; i++) {
        cin>>num[i];
    }
    
    
    sort(num, num+n);
    
    
    for (long long int i=0; i<n; i++) {
        if (s1.count(num[i])==0) {
            cnt++;
            s1.insert(k*num[i]);
        }
    }
    printf("%lld",cnt);
}