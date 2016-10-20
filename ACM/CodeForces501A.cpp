// Wrote by MenYifan on 2015-04-15 21:34:20
// Exe.Time 31ms Exe.Memory 4K
//
//  20150415i.cpp
//  Cfiles
//
//  Created by ??? on 15/4/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100050
int main(){
    double a,b,c,d;
    double p1,p2,pM,pV;
    cin>>a>>b>>c>>d;
    p1=3*a/10;
    p2=a-a/250*c;
    if (p1>p2) {
        pM=p1;
    }
    else
        pM=p2;
    
    p1=3*b/10;
    p2=b-b/250*d;
    if (p1>p2) {
        pV=p1;
    }
    else
        pV=p2;
    if (pM>pV) {
        cout<<"Misha"<<endl;
    }
    else if(pM<pV){
        cout<<"Vasya"<<endl;
    }
    else
        cout<<"Tie"<<endl;
}
