// Wrote by MenYifan on 2015-07-23 16:01:10
// Exe.Time 329ms Exe.Memory 4892K
//
//  20150723c.cpp
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
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 1000500
int normal[maxn]={0},cnt=0,prime[maxn]={0};
void isPri(){
    //????0????1
    prime[0]=1;
    for (ll i=2; i<maxn; i++) {
        if (normal[i]==0) {//??normal[i]!=0????t(t<i)?i??????i?????????
            prime[++cnt]=i;
            normal[i]=i;
            for (ll k=i*i; k<maxn; k+=i) {
                normal[k]=1;//??????1????????k=i????k???????
                //?int k=i?normal[k]=i,?normal[k]???k???????
            }
        }
    }
}

int main(){
    isPri();
    int t;
    while (sf(t),t) {
        for (int i=1; i<cnt; i++) {
            if (normal[t-prime[i]]!=1) {
                pf("%d = %d + %d\n",t,prime[i],t-prime[i]);
                break;
            }
        }
    }
}