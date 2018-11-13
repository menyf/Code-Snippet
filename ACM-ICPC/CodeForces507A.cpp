// Wrote by MenYifan on 2015-04-16 21:11:50
// Exe.Time 15ms Exe.Memory 16K
//
//  20150415e.cpp
//  Cfiles
//
//  Created by ??? on 15/4/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100050
struct ins{
    int index;
    int days;
};
int cmp(ins a,ins b){
    return a.days<b.days;
}
int main(){
    int n,k,sum=0;
    ins a[105];
    cin>>n>>k;
    for (int i; i<n; i++) {
        scanf("%d",&a[i].days);
        a[i].index=i;
    }
    sort(a, a+n,cmp);
    
    int t=0;
    
    while (sum<=k&&t<n) {
        sum+=a[t++].days;
    }
    if (sum>k) {
        t--;
    }
    
    printf("%d\n",t);
    for (int i=0; i<t; i++) {
        printf("%d",a[i].index+1);
        if (i!=t-1) {
            printf(" ");
        }
    }
}