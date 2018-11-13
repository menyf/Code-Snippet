// Wrote by MenYifan on 2015-04-13 00:10:36
// Exe.Time 30ms Exe.Memory 4K
//
//  20150412g.cpp
//  Cfiles
//
//  Created by ??? on 15/4/13.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    char ch[20];
    scanf("%s",ch);
    for (int i=0; ch[i]!='\0'; i++) {
        if (i==0) {
            if (ch[i]>='5'&&ch[i]<='8') {
                ch[i]='9'-ch[i]+'0';
            }
        }
        else{
            if (ch[i]>='5') {
                ch[i]='9'-ch[i]+'0';
            }
        }
    }
    printf("%s",ch);
}