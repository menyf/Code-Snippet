// Wrote by MenYifan on 2015-07-09 19:33:07
// Exe.Time 30ms Exe.Memory 16K
//
//  20150709a.cpp
//  Cfiles
//
//  Created by ??? on 15/7/7.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,a[150]={},f,b,min=9999;
    cin>>n;
    cin>>a[1];
    for (int i=2; i<=n; i++) {
        cin>>a[i];
        if (fabs(a[i]-a[i-1])<min) {
            min=fabs(a[i-1]-a[i]);
            f=i-1;
            b=i;
        }
    }
    if (fabs(a[n]-a[1])<min) {
        min=fabs(a[n]-a[1]);
        f=n;
        b=1;
    }
    printf("%d %d",f,b);
}