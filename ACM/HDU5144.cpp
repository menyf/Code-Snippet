// Wrote by MenYifan on 2016-08-08 20:34:40
// Exe.Time 187ms Exe.Memory 1600K
//
//  20150726j.cpp
//  Cfiles
//
//  Created by ??? on 15/7/26.
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
#define g 9.8
double v0,H;
double dis(double theta){
    return v0*cos(theta)*(v0*sin(theta)/g+sqrt(2*H/g+v0*v0*sin(theta)*sin(theta)/(g*g)));
}
int main(){
    int t;
    sf(t);
    while (t--) {
        scanf("%lf%lf",&H,&v0);
        double a,b,l=0,r=PI/2,mid,midmid,ans;
        while (r-l>eps) {
            mid=(l+r)/2;
            midmid=(mid+r)/2;
            a=dis(mid);
            b=dis(midmid);
            if(a<b)
                l=mid;
            else
                r=midmid;
        }
        ans=dis(l);
        pf("%.2f\n",ans);
    }
}