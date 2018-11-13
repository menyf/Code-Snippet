// Wrote by MenYifan on 2015-04-07 22:52:49
// Exe.Time 31ms Exe.Memory 984K
//
//  20150406g.cpp
//  Cfiles
//
//  Created by ??? on 15/4/6.
//  Copyright (c) 2015? ???. All rights reserved.
//????

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int judge[200050];
void swap(char *p1,char *p2){
    char temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int main(){
    char ss[200050];
    scanf("%s",ss);
    int len=strlen(ss);
    int n;
    scanf("%d",&n);
    while (n--) {
        int p;
        scanf("%d",&p);
        judge[p-1]++;
    }
    if (judge[0]%2) {
        swap(ss[0], ss[len-1]);
    }
    for (int i=1; i<len/2; i++) {
        judge[i]+=judge[i-1];
        if (judge[i]%2==1) {
            swap(ss[i], ss[len-i-1]);
            judge[i]=1;
        }
        else
            judge[i]=0;
    }
    printf("%s",ss);
}