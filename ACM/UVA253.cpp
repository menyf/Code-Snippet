// Wrote by MenYifan on 2015-09-27 19:44:49
// Exe.Time 0ms Exe.Memory 0K
//
//  20150927a.cpp
//  Cfiles
//
//  Created by ??? on 15/9/27.
//  Copyright   2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    char s1[20],s2[10];
    while (scanf("%6s%6s",s1,s2)!=EOF) {
        bool hi[3];
        for (int i=0; i<3; i++) {
            hi[i]=false;
            for (int j=0; j<6; j++) {
                if (s1[i]==s2[j]&&s1[5-i]==s2[5-j]) {
                    hi[i]=true;
                    s2[j]=s2[5-j]='.';
                    break;
                }
            }
        }
        
    tag:
        if (hi[0]&&hi[1]&&hi[2])
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }
}