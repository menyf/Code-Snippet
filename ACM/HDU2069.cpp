// Wrote by MenYifan on 2015-07-24 11:50:44
// Exe.Time 31ms Exe.Memory 1584K
//
//  20150724b.cpp
//  Cfiles
//
//  Created by ??? on 15/7/24.
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
int main(){
    int n,cnt;
    while (scanf("%d",&n)!=EOF) {
        cnt=0;
//        if (n==0) {
//            printf("1\n");
//            continue;
//        }
        for (int a=0; a<=n/50; a++) {
            for (int b=0; b<=(n-50*a)/25; b++) {
                for (int c=0; c<=(n-50*a-25*b); c++) {
                    for (int d=0; d<=(n-50*a-25*b-10*c); d++) {
                        for (int e=0; e<=(n-50*a-25*b-10*c-5*d); e++) {
                            if (50*a+25*b+10*c+5*d+e==n&&a+b+c+d+e<=100) {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
}