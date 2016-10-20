// Wrote by MenYifan on 2015-10-09 19:14:41
// Exe.Time 62ms Exe.Memory 8K
//
//  20151009a.cpp
//  Cfiles
//
//  Created by ??? on 15/10/9.
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
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define vset(a,val) memset(a,val,sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    int n,tmp,a[105],ans=0;
    sf(n);
    for (int i=0; i<n; i++) {
        sf(a[i]);
    }
    for (int i=0; i<n; i++) {
        tmp=0;
        for (int j=i; j<n; j++) {
            tmp=tmp^a[j];
            ans=max(tmp, ans);
        }
    }
    cout<<ans<<endl;
}