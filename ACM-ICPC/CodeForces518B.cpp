// Wrote by MenYifan on 2015-04-13 01:31:51
// Exe.Time 30ms Exe.Memory 16K
//
//  20150412d.cpp
//  Cfiles
//
//  Created by ??? on 15/4/13.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    char ch;
    int s[150]={},t[150]={},w=0,y=0;
    
    while ((ch=getchar())!='\n') {
        s[ch]++;
    }
    while ((ch=getchar())!='\n') {
        t[ch]++;
    }
    
    for (int i='a';i<='z' ; i++) {
        //????????
        int tmp = min(s[i], t[i]) + min(s[i - 32], t[i - 32]);
        y += tmp;
        w += min(s[i] + s[i - 32], t[i] + t[i - 32]) - tmp;
    }
    cout<<y<<" "<<w<<endl;
}