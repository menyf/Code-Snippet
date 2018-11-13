// Wrote by MenYifan on 2015-04-12 21:24:03
// Exe.Time 31ms Exe.Memory 4K
//
//  20150412e.cpp
//  Cfiles
//
//  Created by ??? on 15/4/12.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 100050
int main(){
    long long int a,b,n;
    scanf("%lld %lld %lld",&a,&b,&n);
    if (a<0) {
        a=-a;
    }
    if (b<0) {
        b=-b;
    }
    if (a==0&&b==0) {
        if (n%2==0) {
            printf("Yes");
            return 0;
        }
    }
    if ((n-a-b)%2||n<a+b) {
        printf("No");
    }
    else
        printf("Yes");
    return 0;
}