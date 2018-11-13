// Wrote by MenYifan on 2015-05-31 21:54:27
// Exe.Time 15ms Exe.Memory 4K
//
//  20150531g.cpp
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
int main(){
    int sum,a;
    for (int i=0; i<5; i++) {
        cin>>a;
        sum+=a;
    }
    if (sum!=0&&sum%5==0) {
        cout<<sum/5<<endl;
    }
    else
        printf("-1\n");
}