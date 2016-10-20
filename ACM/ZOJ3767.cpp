// Wrote by MenYifan on 2015-03-31 18:25:48
// Exe.Time 0ms Exe.Memory 272K
//
//  20150331a.cpp
//  Cfiles
//
//  Created by ??? on 15/3/31.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int t,m,n,w;
    cin>>t;
    while (t--) {
        int sum=0;
        cin>>n>>m;
        for (int i=0; i<n; i++) {
            cin>>w;
            sum+=w;
        }
        if (sum>m) {
            cout<<"Warning"<<endl;
        }
        else
            cout<<"Safe"<<endl;
    }
}