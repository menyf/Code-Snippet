//
//  POJ3461.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/5/28.
//  Copyright (c) 2015年 门一凡. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define lenW 10000+10
#define lenT 1000000+10
int len1,len2;
void getnext(char *w,int *next){
    int i=0,j=-1;
    next[0]=-1;
    while (i<len2) {
        if (j==-1||w[i]==w[j]) {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int kmp(char *t,char *w){
    int i=0,j=0,cnt=0;
    int next[lenW];
    len1=(int)strlen(t);
    len2=(int)strlen(w);
    getnext(w, next);
    while (i<len1&&j<len2) {
        if (j==-1||t[i]==w[j]) {
            i++,j++;
        }
        else
            j=next[j];
        if (j==len2) {
            cnt++;
            j=next[j];
        }
    }
    return cnt;
}
int main(){
    int T;
    cin>>T;
    char w[lenW],t[lenT];
    while (T--) {
        scanf("%s%s",w,t);
        cout<<kmp(t, w)<<endl;
    }
}
