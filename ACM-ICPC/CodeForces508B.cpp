// Wrote by MenYifan on 2015-04-15 19:19:57
// Exe.Time 30ms Exe.Memory 100K
//
//  20150415d.cpp
//  Cfiles
//
//  Created by ??? on 15/4/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 100050
void swap(int *p1,int *p2){
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int main(){
    char str[MAX];
    int p=-1,i;
    char ch;
    bool flag=false;//?????????
    scanf("%s",str);
    int len=strlen(str);
    
    for (i=0; i<len; i++) {
        if ((str[i]-'0')%2==0) {
            flag=1;//????
            if (str[i]<str[len-1]) {
                //????????
                swap(str[i], str[len-1]);
                break;
            }
            else{
                //?????
                ch=str[i];
                p=i;
            }
        }
    }
    if (p!=-1&&i==len) {
        swap(str[p], str[len-1]);
    }
    if (flag) {
        printf("%s",str);
    }
    else
        printf("-1");
}