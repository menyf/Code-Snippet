// Wrote by MenYifan on 2015-03-29 21:57:38
// Exe.Time 249ms Exe.Memory 4904K
//
//  20150329h.cpp
//  Cfiles
//
//  Created by ??? on 15/3/29.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "cstring"
using namespace std;
char s[1000000+50];
int a[1000000+50];
int main(){
    scanf("%s",s);

    int len=strlen(s);
    int r=0,cnt=0,l=len-1;
    for (int i=0; i<len; i++) {
        if (s[i]=='r') {
            a[r++]=i+1;
        }
        else
            a[l--]=i+1;
    }

    for (int i=0; i<len; i++) {
        printf("%d\n",a[i]);
    }
}