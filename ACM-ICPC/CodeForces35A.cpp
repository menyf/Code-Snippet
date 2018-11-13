// Wrote by MenYifan on 2015-07-09 20:00:28
// Exe.Time 30ms Exe.Memory 184K
//
//  20150709c.cpp
//  Cfiles
//
//  Created by ??? on 15/7/9.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int aim,a,b;
    int s[3]={};
    cin>>aim;
    s[aim-1]=1;
    for (int i=0; i<3; i++) {
        cin>>a>>b;
        swap(s[a-1], s[b-1]);
    }
    if (s[0]==1) {
        printf("1");
    }
    else if(s[1]==1)
        printf("2");
    else
        printf("3");
}