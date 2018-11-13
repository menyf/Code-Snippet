// Wrote by MenYifan on 2015-04-19 20:15:22
// Exe.Time 15ms Exe.Memory 2020K
//
//  20150418d.cpp
//  Cfiles
//
//  Created by ??? on 15/4/19.
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
#define MAX 10050
#define inf 9999999
int f(int n){
    switch (n) {
        case 0:
            return 2;
            break;
            
        case 1:
            return 7;
            break;
            
        case 2:
            return 2;
            break;
            
        case 3:
            return 3;
            break;
            
        case 4:
            return 3;
            break;
            
        case 5:
            return 4;
            break;
            
            
        case 6:
            return 2;
            break;
            
        case 7:
            return 5;
            break;

        case 8:
            return 1;
            break;
            
        case 9:
            return 2;
            break;
            
        default:
            return 0;
    }
}
int main(){
    int n;
    cin>>n;
    int x,y;
    x=n/10;
    y=n%10;
    cout<<f(x)*f(y)<<endl;
}