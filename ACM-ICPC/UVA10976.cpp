// Wrote by MenYifan on 2015-09-27 20:17:20
// Exe.Time 3ms Exe.Memory 0K
//
//  20150927d.cpp
//  Cfiles
//
//  Created by ??? on 15/9/27.
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
#define eps 1e-4
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    int k;
    while (cin>>k) {
        int t=0;
        int a[maxn]={},b[maxn]={};
        for (int i=k+1; i<=2*k; i++) {
            double tmp=1/(1.0/k-1.0/i);
            if (fabs((int)(tmp+1)-tmp)<eps) {
                //??
                a[t]=i;b[t]=(int)(tmp+1);
                t++;
            }
            if (fabs((int)tmp-tmp)<eps) {
                a[t]=i;b[t]=(int)tmp;
                t++;
            }
        }
        cout<<t<<endl;
        for (int i=0; i<t; i++) {
            printf("1/%d = 1/%d + 1/%d\n",(int)k,b[i],a[i]);
        }
    }
}