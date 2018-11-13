// Wrote by MenYifan on 2015-05-26 06:55:28
// Exe.Time 30ms Exe.Memory 4K
//
//  20150524c.cpp
//  Cfiles
//
//  Created by ??? on 15/5/24.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#define maxn 100050
#define inf 999999
#define PI acos(-1.0)
#define debug puts("-------------------");
using namespace std;
int main(){
    int m,s,pos=0,tmps;
    char a[110]={},b[110]={};
    memset(a, '0', sizeof(a));
    memset(b, '0', sizeof(b));
    cin>>m>>s;
    if (m==1&&s==0) {
        puts("0 0");
        return 0;
    }
    if ((s==0)||9*m<s) {
        printf("-1 -1\n");
    }
    else{
        tmps=s;
        pos=0;
        a[m]='\0';
        b[m]='\0';
        while (tmps) {
            if (tmps>9) {
                a[pos]=9+'0';
                tmps-=9;
                pos++;
            }
            else{
                a[pos]=tmps+'0';
                tmps=0;
            }
        }
        
        b[0]='1';
        tmps=s-1;
        pos=m-1;
        while (tmps) {
            if (tmps>9) {
                b[pos]=9+'0';
                tmps-=9;
                pos--;
            }
            else{
                b[pos]+=tmps;
                tmps=0;
            }
        }
        printf("%s %s",b,a);
    }
        
}