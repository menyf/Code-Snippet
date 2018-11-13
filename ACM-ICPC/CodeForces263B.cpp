// Wrote by MenYifan on 2015-03-29 20:11:17
// Exe.Time 60ms Exe.Memory 4K
//
//  20150329d.cpp
//  Cfiles
//
//  Created by ??? on 15/3/29.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    long long a[55];
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%lld",a+i);
    }
    sort(a,a+n);
    if (k>n) {
        printf("-1");
        return 0;
    }
    else{
        printf("%lld %lld",a[n-k],a[n-k]);
    }
    
}