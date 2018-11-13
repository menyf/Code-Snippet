// Wrote by MenYifan on 2015-07-30 16:36:16
// Exe.Time 31ms Exe.Memory 16K
//
//  20150730d.cpp
//  Cfiles
//
//  Created by ??? on 15/7/30.
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
#define maxn 4005
int main(){
    int x,k,tmp1,tmp2,c,mx=0,mn=0;
    int a[maxn]={1};
    sff(x, k);
    
    for (int i=0; i<k; i++) {
        sf(c);
        if (c==1) {
            sff(tmp1, tmp2);
            a[tmp1]=a[tmp2]=1;
            mx+=2;
        }
        else{
            sf(tmp1);
            a[tmp1]=1;
            mx+=1;
        }
    }
    
    for (int i=1; i<x; i++) {
        if (a[i]==0&&a[i+1]==1) {
            mn++;
        }
        else if (a[i]==0&&a[i+1]==0){
            mn++;
            i++;
        }
    }
    cout<<mn<<" "<<x-1-mx<<endl;
}