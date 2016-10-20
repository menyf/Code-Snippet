// Wrote by MenYifan on 2015-07-22 13:52:12
// Exe.Time 0ms Exe.Memory 4576K
//
//  20150722d.cpp
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
#define maxn 390000
int a[maxn]={},b[maxn]={};
int wzf(int n, int m)
{
    if(n > m)
        swap(n, m);
    int k = m-n;
    int a = (k * (1.0 + sqrt(5.0))/2.0);
    if(a == n)
        return 0;//???
    else
        return 1;//???
}
void init(){
    int i;
    for (i=1; i<maxn; i++) {
        a[i]= (i * (1.0 + sqrt(5.0))/2.0);
        b[i]=a[i]+i;
//        pf("%d : %d %d\n",i,a[i],b[i]);
        if (b[i]>1000000) {
            break;
        }
    }
}
int main(){
    init();
    int x,y,i;
    while (sff(x, y),x+y) {
        
        //x y????
        if (wzf(x, y)==0) {
            pf("0\n");
            continue;
        }
        
        pf("1\n");
        // x?y
        if (x==y) {
            printf("0 0\n");
            for (i=1; b[i]<y; i++);
            if (b[i]==y)
                printf("%d %d\n",a[i],b[i]);
            continue;
        }
        
        //x!=y
        int dis=y-x;
        if (a[dis]<=x&&b[dis]<=y) {
            printf("%d %d\n",a[dis],b[dis]);
        }
        for (i=1; b[i]<=y; i++) {
            if (b[i]==y&&a[i]<=x)
                pf("%d %d\n",a[i],b[i]);
            if (b[i]==x&&a[i]<=y)
                pf("%d %d\n",a[i],b[i]);
            if (a[i]==y&&b[i]<=x)
                pf("%d %d\n",a[i],b[i]);
            if (a[i]==x&&b[i]<=y)
                pf("%d %d\n",a[i],b[i]);
        }
        
    }
}