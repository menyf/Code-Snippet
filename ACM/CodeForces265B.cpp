// Wrote by MenYifan on 2015-03-29 20:55:30
// Exe.Time 62ms Exe.Memory 8K
//
//  20150329g.cpp
//  Cfiles
//
//  Created by ??? on 15/3/29.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
long long f(long long t_p,long long t_l){
    if (t_p>t_l) {
        return t_p-t_l;
    }
    else
        return t_l-t_p;
}//??p????l????
int main(){
    long long time=0;
    int n,p=0,l=0;
    cin>>n;
    while (n--) {
        time+=2;
        scanf("%d",&l);
        time+=f(p, l);
        p=l;
    }
    printf("%lld",time-1);
}