// Wrote by MenYifan on 2015-10-25 18:15:57
// Exe.Time 0ms Exe.Memory 0K
//
//  20151025a.cpp
//  Cfiles
//
//  Created by ??? on 15/10/25.
//  Copyright   2015? ???. All rights reserved.
//

#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    int n,cas=0;
    while (scanf("%d",&n)&&n>0) {
        int tmp=1,cnt=0;
        while (1) {
            if (tmp>=n) {
                break;
            }
            tmp*=2;
            cnt++;
        }
        printf("Case %d: %d\n",++cas,cnt);
    }
}