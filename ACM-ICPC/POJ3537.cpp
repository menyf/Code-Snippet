// Wrote by MenYifan on 2015-07-22 20:53:03
// Exe.Time 454ms Exe.Memory 5920K
//
//  20150722f.cpp
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
int sg[2005]={};
int dfs(int n){
    if (n<=0) {
        return 0;
    }
    
    if (sg[n]>=0) {
        return sg[n];
    }
    int vis[2004]={0};
    int& ans=sg[n];
    
    for (int i=1; i<=n; i++) {
        vis[dfs(i-3)^dfs(n-i-2)]=1;
    }
    int id=0;
    while(vis[id])id++;
    return ans=id;
}
int main(){
    memset(sg, -1, sizeof(sg));
    int n;
//    dfs(2004);
    while (sf(n)!=EOF) {
    if (dfs(n)) {
        pf("1\n");
    }
    else
        pf("2\n");
    }
}