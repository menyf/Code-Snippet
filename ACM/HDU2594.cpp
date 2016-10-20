// Wrote by MenYifan on 2015-05-31 09:19:47
// Exe.Time 15ms Exe.Memory 2072K
//
//  20150529c.cpp
//  Cfiles
//
//  Created by ??? on 15/5/29.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 50005
void getnext(char *s,int *next,int len){
    int i=0,j=-1;
    next[0]=-1;
    while (i<len) {
        if (j==-1||s[i]==s[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}
void kmp(char *s,char *sub,int *next,int len1,int len2){
    int i=0,j=0;
    while (i<len1) {
        if (j==-1||s[i]==sub[j]) {
            i++,j++;
        }
        else{
            j=next[j];
        }
    }
    if (j==0) {
        cout<<"0"<<endl;
    }
    else{
        for (i=0; i<j; i++) {
            cout<<sub[i];
        }
        cout<<" "<<j<<endl;
    }
}
int main(){
    void getnext(char *s,int *next,int len);
    void kmp(char *s,char *sub,int *next,int len1,int len2);
    char s[maxn],sub[maxn];
    int len1,len2,next1[maxn*2];
    while (scanf("%s %s",sub,s)!=-1) {
        len1=strlen(s);
        len2=strlen(sub);
        getnext(sub,next1,len2);
        kmp(s,sub,next1,len1,len2);
    }
}