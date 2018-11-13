// Wrote by MenYifan on 2015-07-22 11:02:58
// Exe.Time 15ms Exe.Memory 1576K
//
//  20150722b.cpp
//  Cfiles
//
//  Created by ??? on 15/7/22.
//  Copyright (c) 2015? ???. All rights reserved.
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
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 10005
int wzf(int n, int m)
{
    if(n > m)
        swap(n, m);
    int k = m-n;
    int a = (k * (1.0 + sqrt(5.0))/2.0);
    if(a == n)
        return 0;
    else
        return 1;
}
int main(){
    int a,b;
    while (sff(a, b)!=EOF) {
        pf("%d\n",wzf(a, b));
    }
}