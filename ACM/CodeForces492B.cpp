// Wrote by MenYifan on 2015-05-17 19:00:02
// Exe.Time 15ms Exe.Memory 4K

//
//  20150517b.cpp
//  Cfiles
//
//  Created by ??? on 15/5/17.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1005
#define inf 9999999
int main(){
    int n,l,dMax=0;
    double ans;
    int a[MAX];
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    for (int i=1; i<n; i++) {
        if (a[i]-a[i-1]>dMax) {
            dMax=a[i]-a[i-1];
        }
    }
    ans=dMax/2.0;
    if (a[0]>ans) {
        ans=a[0];
    }
    if (l-a[n-1]>ans){
        ans=l-a[n-1];
    }
    printf("%.10lf",ans);
    return 0;
}