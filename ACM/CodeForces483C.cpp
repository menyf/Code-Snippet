// Wrote by MenYifan on 2015-05-31 20:10:04
// Exe.Time 46ms Exe.Memory 4K
//
//  20150531c.cpp
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
    bool flag=true;
    int n,k,tmp;
    cin>>n>>k;
    for (; n>k+1; n--) {
        printf("%d ",n);
    }
    int end=(n+1)/2;
    tmp=n-1;
    while (n!=end) {
        printf("%d ",n);
        if (flag) {
            n-=tmp;
            flag=false;
        }
        else{
            n+=tmp;
            flag=true;
        }
        tmp--;
    }
    cout<<n;
}