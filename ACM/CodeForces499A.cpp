// Wrote by MenYifan on 2015-04-15 22:01:54
// Exe.Time 15ms Exe.Memory 8K
//
//  20150415k.cpp
//  Cfiles
//
//  Created by ??? on 15/4/15.
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
#define MAX 100050
int main(){
    int n,x,p=0,l,r,sum=0;
    cin>>n>>x;
    for (int i=0; i<n; i++) {
        cin>>l>>r;
        sum+=(l-1-p)%x+r-l+1;
        p=r;
    }
    printf("%d",sum);
}