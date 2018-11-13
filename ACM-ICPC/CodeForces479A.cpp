// Wrote by MenYifan on 2015-05-31 20:16:53
// Exe.Time 15ms Exe.Memory 4K
//
//  20150531d.cpp
//  Cfiles
//
//  Created by ??? on 15/5/31.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
using namespace std;
#define ll long long
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int max=0;
    if (a+b+c>max) {
        max=a+b+c;
    }
    if (a+b*c>max) {
        max=a+b*c;
    }
    if ((a+b)*c>max) {
        max=(a+b)*c;
    }
    if (a*b+c>max) {
        max=a*b+c;
    }
    if (a*(b+c)>max) {
        max=a*(b+c);
    }
    if (a*b*c>max) {
        max=a*b*c;
    }
    printf("%d",max);
}