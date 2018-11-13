// Wrote by MenYifan on 2015-05-31 19:26:57
// Exe.Time 15ms Exe.Memory 4K
//
//  20150531a.cpp
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
    ll l,r;
    scanf("%lld %lld",&l,&r);
    for (ll i=l; i<r; i++) {
        for (ll j=r; j>i; j--) {
            if (__gcd(i,j)!=1) {
                for (ll k=i+1; k<j; k++) {
                    if (__gcd(i,k)==1&&__gcd(j,k)==1) {
                        printf("%lld %lld %lld\n",i,k,j);
                        return 0;
                    }
                }
            }
        }
    }
    printf("-1\n");
    return 0;

}