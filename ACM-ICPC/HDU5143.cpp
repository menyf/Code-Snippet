// Wrote by MenYifan on 2016-08-08 20:34:21
// Exe.Time 62ms Exe.Memory 1576K
//
//  20150726i.cpp
//  Cfiles
//
//  Created by ??? on 15/7/27.
//  Copyright (c) 2015? ???. All rights reserved.
//  HDU5143
//  http://www.2cto.com/kf/201412/361337.html

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
//int a[4],b[4];
int main(){
    int t,a,b,c,d,q,w,e,r;
    sf(t);
    while (t--) {
        bool flag=false;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for (int i=0; i<=2; i++) {
            for (int j=0; j<=2; j++) {
                for (int k=0; k<=2; k++) {
                    q=a-i-j;
                    w=b-i-j-k;
                    e=c-i-j-k;
                    r=d-i-k;
                    if ((q==0||q>=3)&&(w==0||w>=3)&&(e==0||e>=3)&&(r==0||r>=3)){
                        flag=true;
                        break;
                    }
                }
                
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}