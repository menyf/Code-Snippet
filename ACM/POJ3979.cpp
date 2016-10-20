// Wrote by MenYifan on 2015-03-20 21:40:54
// Exe.Time 0ms Exe.Memory 672K
//
//  20150320d.cpp
//  Cfiles
//
//  Created by ??? on 15/3/20.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include "algorithm"
#include <stdlib.h>
#include "ctype.h"
#include <iostream>
#include "stdbool.h"
#include "map"
#include "string.h"
using namespace std;
int Gcd(int a, int b)
{
    if(b == 0)
        return a;
    return Gcd(b, a % b);
}
int main(){
    char a,b,c,d,ch;
    int a1,b1,c1,d1,fz,fm,temp;
    while (scanf("%d/%d%c%d/%d",&a1,&b1,&ch,&c1,&d1)!=EOF) {
        fm=b1*d1;
        switch (ch) {
            case '+':
                fz=a1*d1+b1*c1;
                break;
            case '-':
                fz=a1*d1-b1*c1;
                break;
            default:
                break;
        }
        temp=Gcd(fm,fz);
        if (fz==0) {
            printf("0\n");
        }
        else{
            fm/=temp;
            fz/=temp;
            if (fm<0) {
                fm=-fm;
                fz=-fz;
            }
            if (fm==1) {
                printf("%d\n",fz);
            }
            else{
            printf("%d/%d\n",fz,fm);
            }
//        cout<<fz<<"/"<<fm;
        }
    }
}