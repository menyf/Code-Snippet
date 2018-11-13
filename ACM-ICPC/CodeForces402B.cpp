// Wrote by MenYifan on 2015-07-30 16:08:10
// Exe.Time 30ms Exe.Memory 4K
//
//  20150730f.cpp
//  Cfiles
//
//  Created by ??? on 15/7/30.
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
int main(){
    int n,k,tmp=0,fund=0;
    int a[1005]={};
    int p[1005]={};
    sff(n, k);
    
    for (int i=1; i<=n; i++) {
        sf(a[i]);
        if (a[i]-k*(i-1)>0) {
            p[a[i]-k*(i-1)]++;
        }
    }
    
    for (int i=0; i<1005; i++) {
        if (p[i]>tmp) {
            tmp=p[i];
            fund=i;
        }
    }
    
    cout<<n-p[fund]<<endl;
    for (int i=1; i<=n; i++) {
        if (a[i]<fund+k*(i-1)) {
            printf("+ %d %d\n",i,fund+k*(i-1)-a[i]);
        }
        else if (a[i]>fund+k*(i-1)){
            printf("- %d %d\n",i,-fund-k*(i-1)+a[i]);
        }
    }
}