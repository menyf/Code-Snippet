// Wrote by MenYifan on 2015-07-27 19:48:58
// Exe.Time 3563ms Exe.Memory 8728K
//
//  20150727i.cpp
//  Cfiles
//
//  Created by ??? on 15/7/27.
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
/*
 ???1??
 */
const int NV = 150005;
const int NVB = 20;
int mx[NV][NVB],mn[NV][NVB],a[NV];
void init(int data[],int n)
{
    int k = log2(n);
    for(int i=1; i<=n; i++)
        mx[i][0] = mn[i][0] = data[i];
    for(int j=1; j<=k; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r,int flag)
{
    int k = log2(r-l+1);
    if(flag)
        return max(mx[l][k],mx[r-(1<<k)+1][k]);
    else
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int main(){
    int n,q,x,y,b,s;
    sff(n, q);
    for (int i=1; i<=n; i++)
        sf(a[i]);
    init(a, n);
    while (q--) {
        scanf("%d%d",&x,&y);
        b=query(x,y,1);
        s=query(x,y,0);
        pf("%d\n",b-s);
        
    }
}