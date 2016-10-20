// Wrote by MenYifan on 2015-10-19 15:58:10
// Exe.Time 3579ms Exe.Memory 5084K
//
//  20151018g.cpp
//  Cfiles
//
//  Created by ??? on 15/10/19.
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
#define debug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 200005;
int add[NV<<2],sum[NV<<2];
int o[NV],a[NV],t[NV];
void PushUp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt=1)
{
    if (l == r)
    {
        sum[rt]=1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int c,int l,int r,int rt=1)
{
    if (l==r )
    {
        sum[rt] = 0;
        o[l]=c;
        return;
    }
    int m = (l + r) >> 1;
    if (sum[rt<<1] >= L) update(L , c , lson);
    else update(L-sum[rt<<1], c , rson);
    PushUp(rt);
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d %d",&a[i],&t[i]);
        }
        build(1, n);
        for (int i=n-1; i>=0; i--) {
            update(a[i]+1, t[i], 1, n);
        }
        for (int i=1; i<=n; i++) {
            printf("%d ",o[i]);
        }
        cout<<endl;
    }
}
