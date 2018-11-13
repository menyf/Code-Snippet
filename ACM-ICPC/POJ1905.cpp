// Wrote by MenYifan on 2015-03-27 21:19:40
// Exe.Time 0ms Exe.Memory 788K
//
//  20150327a.cpp
//  Cfiles
//
//  Created by ??? on 15/3/27.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main(){
    double len,n,c;
    while (cin>>len>>n>>c) {
        if (len==-1&&n==-1&&c==-1) {
            break;
        }
        double relen=(1+n*c)*len;
        double start=0,end=len/2,temp;
        while (end-start>1e-6) {
            temp=(start+end)/2;
            double r=(4*temp*temp+len*len)/(8*temp);
            double s=2*r*asin(len/(2*r));
            if (s<relen) {
                start=temp;
            }
            else
                end=temp;
        }
        printf("%.3f\n",start);
    }
}
