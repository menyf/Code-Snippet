// Wrote by MenYifan on 2015-03-29 22:40:58
// Exe.Time 686ms Exe.Memory 396K
//
//  20150329b.cpp
//  Cfiles
//
//  Created by ??? on 15/3/29.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int price[100000+50];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int m,q,min,n;
 
    long long tot=0;
    cin>>m;
    
    //????q ???min
    for (int i=0; i<m; i++) {
        cin>>q;
        if (i==0) {
            min=q;
        }
        if (min>q) {
            min=q;
        }
    }
    
    //????
    cin>>n;

    for (int i=0; i<n; i++) {
        cin>>price[i];
    }
    
    //??
    sort(price, price+n, cmp);

    int cnt=0;
    for (int i=0; i<n; i++) {
        if (cnt==min) {
            i+=2;//???? ????free?
            cnt=0;//????
        }
        tot+=price[i];
        cnt++;
    }
    
    printf("%lld",tot);
    
}
