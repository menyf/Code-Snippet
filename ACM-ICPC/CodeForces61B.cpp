// Wrote by MenYifan on 2015-07-15 09:16:07
// Exe.Time 31ms Exe.Memory 24K
//
//  20150714h.cpp
//  Cfiles
//
//  Created by ??? on 15/7/14.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;
int LEN=0;
char s[3][150];
char ss[650];
char str[6][400];

void init(char *a){
    int i=0,j=0;
    while (a[i]!='\0') {
        if (a[i]>='A'&&a[i]<='Z') {
            a[j]=a[i]+32;
            j++;
        }
        else if (a[i]>='a'&&a[i]<='z') {
            a[j]=a[i];
            j++;
        }
        i++;
    }
    a[j]='\0';
//    printf("%s*****\n",a);
}
int main(){
    int n;
    for (int i=0; i<3; i++) {
        scanf("%s",s[i]);
        init(s[i]);
    }
    
    strcat(str[0], s[0]);
    strcat(str[0], s[1]);
    strcat(str[0], s[2]);
    
    strcat(str[1], s[0]);
    strcat(str[1], s[2]);
    strcat(str[1], s[1]);
 
    strcat(str[2], s[1]);
    strcat(str[2], s[0]);
    strcat(str[2], s[2]);
 
    strcat(str[3], s[1]);
    strcat(str[3], s[2]);
    strcat(str[3], s[0]);
 
    strcat(str[4], s[2]);
    strcat(str[4], s[0]);
    strcat(str[4], s[1]);
 
    strcat(str[5], s[2]);
    strcat(str[5], s[1]);
    strcat(str[5], s[0]);
    
    
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%s",ss);
        init(ss);
        if (strcmp(ss, str[0])==0||strcmp(ss, str[1])==0||strcmp(ss, str[2])==0||strcmp(ss, str[3])==0||strcmp(ss, str[4])==0||strcmp(ss, str[5])==0) {
            printf("ACC\n");
        }
        else
            printf("WA\n");
//    label:continue;
        
    }
    

}