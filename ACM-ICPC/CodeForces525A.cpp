// Wrote by MenYifan on 2015-04-06 22:29:08
// Exe.Time 31ms Exe.Memory 4K
//
//  20150406f.cpp
//  Cfiles
//
//  Created by ??? on 15/4/6.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;
int main(){
    int n,cnt=0;
    map<char, int>s;
    char ch1,ch2;
    scanf("%d",&n);
    ch1=getchar();
    for (int i=1; i<n; i++) {
        ch1=getchar();  //x
        ch2=getchar();  //Y
        s[ch1]++;       //s[x]=1
        if (s[ch2+32]>0) {
            s[ch2+32]--;
          //  printf("%c %d\n",ch2+32,s[ch2-32]);
        }
        else
            cnt++;
    }
    cout<<cnt<<endl;
}