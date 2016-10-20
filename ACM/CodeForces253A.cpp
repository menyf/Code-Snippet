// Wrote by MenYifan on 2015-10-16 19:12:48
// Exe.Time 30ms Exe.Memory 252K
//
//  20151016a.cpp
//  Cfiles
//
//  Created by ??? on 15/10/16.
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,i,id1=0,id2=0;
    sff(n, m);
    if (n>m) {
        for (int i=0; i<m+n; i++) {
            if (i%2==1&&id2<m) {
                printf("G");
                id2++;
            }
            else{
                pf("B");
                id1++;
            }
        }
    }
    else{
        for (int i=0; i<m+n; i++) {
            if (i%2==1&&id1<n) {
                printf("B");
                id1++;
            }
            else{
                pf("G");
                id2++;
            }
        }
    }
}