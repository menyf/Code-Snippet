// Wrote by MenYifan on 2015-07-14 18:41:07
// Exe.Time 30ms Exe.Memory 4K

//
//  20150714d.cpp
//  Cfiles
//
//  Created by ??? on 15/7/14.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>
using namespace std;
int main(){
    char s[105];
    scanf("%s",s);
    int cnt=0,len=strlen(s);//cnt???????????
    for (int i=0; i<len; i++) {
        if (s[i]<='z'&&s[i]>='a') {
            cnt++;
        }
    }
    if (2*cnt>=len) {
        for (int i=0; i<len; i++) {
            if (s[i]<='Z') {
                printf("%c",s[i]+32);
            }
            else
                printf("%c",s[i]);
        }
    }
    else
    {
        for (int i=0; i<len; i++) {
            if (s[i]>='a') {
                printf("%c",s[i]-32);
            }
            else
                printf("%c",s[i]);
                }
    }
}