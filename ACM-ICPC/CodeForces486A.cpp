// Wrote by MenYifan on 2015-05-24 18:39:34
// Exe.Time 15ms Exe.Memory 20K
//
//  20150524d.cpp
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
    long long n;
    scanf("%lld",&n);
    if (n%2==1) {
        printf("%lld\n",n/2-n);
    }
    else
        printf("%lld\n",n/2);
    
}