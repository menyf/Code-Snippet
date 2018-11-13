// Wrote by MenYifan on 2015-03-15 19:47:46
// Exe.Time 0ms Exe.Memory 1616K
//
//  20150315b.cpp
//  Cfiles
//
//  Created by ??? on 15/3/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include "algorithm"
#include <stdlib.h>
#include "ctype.h"
#include <iostream>
#include "string.h"
#include "map"
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int t;
        cin>>t;
        int num[t];
        for (int j=0; j<t; j++) {
            cin>>num[j];
        }
        sort(num,num+t);
        for (int j=0; j<t; j++) {
            cout<<num[j];
            if (j!=t-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}