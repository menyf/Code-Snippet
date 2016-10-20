// Wrote by MenYifan on 2015-04-19 19:18:08
// Exe.Time 15ms Exe.Memory 2020K
//
//  20150419a.cpp
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
int n;
int f(int array[],int t){
    int max=0;
    for (int i=0; i<n-1; i++) {
        if (i==t) {
            continue;
        }
        else if (i==t-1){
            if (max<array[i+2]-array[i]) {
            max=array[i+2]-array[i];
            }
        }
        else{
            if (max<array[i+1]-array[i]) {
                max=array[i+1]-array[i];
            }
        }
    }
    return max;
}
int main(){
    int num[100];
    int max=inf;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    for (int i=1; i<n-1; i++) {
        if (f(num, i)<max) {
            max=f(num, i);
        }
    }
    cout<<max<<endl;
}