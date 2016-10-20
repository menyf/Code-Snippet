// Wrote by MenYifan on 2015-07-23 17:09:18
// Exe.Time 32ms Exe.Memory 664K
//
//  20150723d.cpp
//  Cfiles
//
//  Created by ??? on 15/7/23.
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
#define sf1(n)       scanf("%d", &n)
#define slf(n)      scanf("%lld",&n)
#define sf2(a,b)    scanf("%d %d", &a, &b)
#define slf2(n)     scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define ins(a)      scanf("%s",a)
#define inss(a,b)   scanf("%s %s",a,b)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn
int main(){
    int x=23,y=28,z=33;
    int k1,k2,k3;
    for (k1=0; k1<z; k1++)
        if (k1*x*y%z==1)
            break;
    for (k2=0; k2<x; k2++)
        if (k2*z*y%x==1)
            break;
    for (k3=0; k3<y; k3++)
        if (k3*x*z%y==1)
            break;
//    cout<<k1*x*y<<endl<<k2*y*z<<endl<<k3*x*z<<endl;
    //    1288          5544          14421
    int a,b,c,d,ans,cnt=0;
    while (scanf("%d%d%d%d",&a,&b,&c,&d)&&a+b+c+d!=-4) {
        ans=(k1*x*y*c+k2*z*y*a+k3*x*z*b-d+x*y*z)%(x*y*z);
        if (ans==0) {
            ans=x*y*z;
        }
        pf("Case %d: the next triple peak occurs in %d days.\n",++cnt,ans);
    }
}