// Wrote by MenYifan on 2015-07-30 14:27:29
// Exe.Time 280ms Exe.Memory 1616K
//
//  20150729c.cpp
//  Cfiles
//
//  Created by ??? on 15/7/30.
//  Copyright (c) 2015? ???. All rights reserved.
//  ??
//  hdu1394

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
    int n,ans,cnt;
    while (sf(n)!=EOF) {
        ans=INF;
        cnt=0;
        int a[maxn]={};
        for (int i=0; i<n; i++)
            sf(a[i]);
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++)
                if (a[i]>a[j])
                    cnt++;
        ans=min(ans,cnt);
        for (int i=0; i<n; i++) {
            cnt=cnt-a[i]+n-1-a[i];
            ans=min(ans, cnt);
        }
        cout<<ans<<endl;
    }
}