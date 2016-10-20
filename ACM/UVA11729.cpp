// Wrote by MenYifan on 2015-10-07 19:31:26
// Exe.Time 3ms Exe.Memory 0K
//
//  20151007b.cpp
//  Cfiles
//
//  Created by ??? on 15/10/7.
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
struct soilder{
    int b,j;
};
bool cmp(soilder a,soilder b){
    return a.j>b.j;
}
int main(){
    int n,cas=0,b,j;
    while (sf(n),n) {
        int ans=0,sumb=0;
        soilder s[n];
        for (int i=0; i<n; i++) {
            sff(s[i].b, s[i].j);
        }
        sort(s, s+n, cmp);
        for (int i=0; i<n; i++) {
            sumb+=s[i].b;
            ans=max(ans, sumb+s[i].j);
        }
        cout<<"Case "<<++cas<<": "<<ans<<endl;
    }
}

//3
//2 5
//3 2 2 1
//3 3 3 4 4 5 5