// Wrote by MenYifan on 2015-05-17 21:43:40
// Exe.Time 31ms Exe.Memory 4K

//
//  20150517g.cpp
//  Cfiles
//
//  Created by ??? on 15/5/17.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int f(int x){
    if (x<0) {
        x=-x;
    }
    while (x>0) {
        if (x%10==8) {
            return 1;
        }
        x/=10;
    }
    return 0;
}
int main(){
    int a,i;
    cin>>a;
    for (i=1; i<20; i++) {
        if (f(a+i)==1) {
            break;
        }
    }
    cout<<i<<endl;
    return 0;
}