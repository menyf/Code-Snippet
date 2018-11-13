// Wrote by MenYifan on 2015-04-15 19:54:52
// Exe.Time 31ms Exe.Memory 4K
//
//  20150415f.cpp
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
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100050
int main(){
    double r,x0,y0,x1,y1;
    cin>>r>>x0>>y0>>x1>>y1;
    double dis=sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
    printf("%.0lf",ceil(dis/(2.0*r)));
}