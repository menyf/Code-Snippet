// Wrote by MenYifan on 2015-07-09 20:04:26
// Exe.Time 62ms Exe.Memory 184K
//
//  20150709e.cpp
//  Cfiles
//
//  Created by ??? on 15/7/9.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,d[105]={},cnt=0,f=-1,b=0;//front back
    cin>>n;
    char s[105];
    scanf("%s",s);
    for (int i=0; i<n; i++) {
        if (s[i]=='1') {
            f=b;
            b=i;
            d[cnt++]=b-f;
        }
    }
    
    for (int i=1; i<cnt-1; i++) {
        if (d[i]!=d[i+1]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}