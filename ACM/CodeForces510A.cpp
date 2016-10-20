// Wrote by MenYifan on 2015-04-12 21:16:25
// Exe.Time 31ms Exe.Memory 4K
//
//  20150412i.cpp
//  Cfiles
//
//  Created by ??? on 15/4/12.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 100050
int main(){
    char ch[50][50];
    memset(ch, '#', sizeof(ch));
    int r,c;
    scanf("%d %d",&r,&c);
    for (int i=1; i<r; i+=2) {
        if (i%4==1) {
            for (int j=0; j<c-1; j++) {
                ch[i][j]='.';
            }
        }
        else{
            for (int j=c-1; j>=1; j--) {
                ch[i][j]='.';
            }
        }
    }
    for (int i=0; i<r; i++) {
     //   printf("%d",i);
        for (int j=0; j<c; j++) {
            printf("%c",ch[i][j]);
        }
        if (i!=r-1) {
            printf("\n");
        }
    }
}