// Wrote by MenYifan on 2015-07-28 15:03:25
// Exe.Time 250ms Exe.Memory 4152K
//
//  20150727l.cpp
//  Cfiles
//
//  Created by ??? on 15/7/28.
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
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 10005
const int NV=255;
const int NVB=20;
int mx[NVB][NV][NV],mn[NVB][NV][NV],a[NV][NV],mxt,mnt;
void init(int data[][NV],int n)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            mx[0][i][j]=mn[0][i][j]=data[i][j];
    for(int k=1; (1<<k)<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j+(1<<k)-1<=n; j++)
            {
                mx[k][i][j]=max(mx[k-1][i][j],mx[k-1][i][j+(1<<k>>1)]);
                mn[k][i][j]=min(mn[k-1][i][j],mn[k-1][i][j+(1<<k>>1)]);
            }
}
///????????
void query(int row,int col,int b)
{
    int k=log2(b);
    mxt=-1;
    mnt=inf;
    int l=col,r=col+b-1;
    for(int i=row; i<row+b; i++)
    {
        mxt=max(mxt,max(mx[k][i][l],mx[k][i][r-(1<<k)+1]));
        mnt=min(mnt,min(mn[k][i][l],mn[k][i][r-(1<<k)+1]));
    }
}
int main()
{
    int n,b,q;
    while(scanf("%d%d%d",&n,&b,&q)!=EOF)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&a[i][j]);
        init(a,n);
        while(q--)
        {
            int r,c;
            scanf("%d%d",&r,&c);
            query(r,c,b);
            printf("%d\n",mxt-mnt);
        }
    }
    return 0;
}
