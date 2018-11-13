// Wrote by MenYifan on 2015-04-13 00:16:22
// Exe.Time 30ms Exe.Memory 36K
//
//  20150412h.cpp
//  Cfiles
//
//  Created by ??? on 15/4/13.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    int n,x0,y0;
    scanf("%d %d %d",&n,&x0,&y0);
    double x,y,k;
    set<double>s;
    for (int i=0; i<n; i++) {
        scanf("%lf %lf",&x,&y);
        if (x==x0) {
            k=99999;
        }
        else
            k=(y-y0)/(x-x0);
        s.insert(k);
    }
    cout<<s.size()<<endl;
}