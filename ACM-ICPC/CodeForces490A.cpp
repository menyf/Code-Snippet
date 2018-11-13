// Wrote by MenYifan on 2015-05-17 19:52:03
// Exe.Time 31ms Exe.Memory 56K
//
//  20150517d.cpp
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
#define MAX 5000
#define inf 9999999
int main(){
    int n,tmp,ta=0,tb=0,tc=0,cnt=0;
    int a[MAX]={},b[MAX]={},c[MAX]={};
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",&tmp);
        if (tmp==1) {
            a[ta++]=i+1;
        }
        else if (tmp==2){
            b[tb++]=i+1;
        }
        else if (tmp==3){
            c[tc++]=i+1;
        }
    }
    for (int i=0; i<n/3; i++) {
        if (a[i]&&b[i]&&c[i]) {
            cnt++;
        }
    }
    cout<<cnt;
    for (int i=0; i<cnt; i++) {
        printf("\n%d %d %d",a[i],b[i],c[i]);
    }
}