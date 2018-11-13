// Wrote by MenYifan on 2015-05-29 22:27:32
// Exe.Time 1232ms Exe.Memory 5612K
//
//  20150529a.cpp
//  Cfiles
//
//  Created by ??? on 15/5/29.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#define lena 1000000+10
#define lenb 10000+10
int m,n;//m??a?? n??b??
int a[lena]={},b[lenb]={};
int next2[lenb]={};
void getnext(int *a,int *next1){
    int i=0,j=-1;
    next1[0]=-1;
    while (i<n) {
        if (j==-1||a[i]==a[j]) {
            next1[++i]=++j;
        }
        else
            j=next1[j];
    }
}
int kmp(int *a,int *b){
    int i=0,j=0;
    while (i<m&&j<n) {
        if (j==-1||a[i]==b[j]) {
            j++,i++;
        }
        else
            j=next2[j];
    }
    if (j==n) {
        return i-j+1;
    }
    else
        return -1;
}
int main(){
    int i,T;
    cin>>T;
    while (T--) {
        cin>>m>>n;
        for (i=0; i<m; i++) {
            scanf("%d",a+i);
        }
        for (i=0; i<n; i++) {
            scanf("%d",b+i);
        }
        getnext(b, next2);
        cout<<kmp(a,b)<<endl;
    }
}