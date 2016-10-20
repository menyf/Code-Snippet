// Wrote by MenYifan on 2015-04-06 21:47:33
// Exe.Time 31ms Exe.Memory 2000K
//
//  20150406e.CPP
//  Cfiles
//
//  Created by ??? on 15/4/6.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
char f[205][2000];
void sum(int o,int p,int q){
    char a[255],b[255],c[255];
    strcpy(a, f[o]);
    strcpy(b, f[p]);
    int i,k=0,al=0,bl=0,cl;

    while(a[al])
        al++;
    
    al--;
    
    while(b[bl])
        bl++;
    
    bl--;
    cl=al>bl?al:bl;cl++;c[cl+1]='\0';
    
    while(cl>=0)
    {
        i=(al>=0?a[al]-'0':0) + (bl>=0?b[bl]-'0':0) + k;
        k=i/10;c[cl]='0'+i%10;
        al--;bl--;cl--;
    }
    int len=strlen(c);
    if (c[0]=='0') {
        for (int i=1; i<len; i++) {
            c[i-1]=c[i];
            if (i==len-1) {
                c[i]='\0';
            }
        }
    }
    strcpy(f[q], c);
}
void make_form(){
    f[1][0]='1';
    f[2][0]='2';
    for (int i=3; i<205; i++) {
        sum(i-2,i-1,i);
     //   f[i]=f[i-1]+f[i-2];
    }
}
int main(){
    make_form();
    int t;
    string s;
    scanf("%d",&t);
    while (t--) {
        cin>>s;
        printf("%s\n",f[s.length()]);
    }
}