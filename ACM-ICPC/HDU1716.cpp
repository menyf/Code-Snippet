// Wrote by MenYifan on 2015-07-24 11:06:20
// Exe.Time 0ms Exe.Memory 1580K
//
//  20150724e.cpp
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
    int a[4];
    int ans[24]={};
    bool flag=false;
    while (scanf("%d%d%d%d",a,a+1,a+2,a+3)&&a[0]+a[1]+a[2]+a[3]) {
        if (flag) {
            printf("\n");
        }
        flag=true;
        int cnt=0,i;
        MemI(ans);
        sort(a,a+4);
        do{
            ans[cnt]=a[0]*1000+a[1]*100+a[2]*10+a[3];
            cnt++;
        }while (next_permutation(a, a+4));

        sort(ans, ans+24);
        for (i=0; i<24; i++)
            if (ans[i]>=1000)
                break;
        
        printf("%d",ans[i++]);
        for (; i<24; i++) {
            if (ans[i]==ans[i-1]) {
                continue;
            }
            else if (ans[i]/1000!=ans[i-1]/1000) {
                printf("\n%d",ans[i]);
            }
            else{
                printf(" %d",ans[i]);
            }
        }
        printf("\n");
    }
}