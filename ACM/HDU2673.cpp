// Wrote by MenYifan on 2015-03-15 21:32:36
// Exe.Time 343ms Exe.Memory 1644K
//
//  20150315h.cpp
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
using namespace std;
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        int num[n];
        for (int i=0; i<n; i++) {
            cin>>num[i];
        }
        sort(num, num+n);
        for (int i=0; i<n/2; i++) {
            printf("%d %d",num[n-i-1],num[i]);
            if (i!=n/2-1) {
                printf(" ");
            }
        }
        if (n%2==1) {
            printf(" %d",num[n/2]);
        }
        printf("\n");
    }
}