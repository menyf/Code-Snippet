// Wrote by MenYifan on 2015-07-20 20:40:03
// Exe.Time 0ms Exe.Memory 1584K
//
//  20150720b.cpp
//  Cfiles
//
//  Created by ??? on 15/7/20.
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
#define MAX 150
char ans[150],s[105];
char tmp[105][105];
int main(){
    int t,cnt=0,l,mx;
    sf(t);
    while (t--) {
        cnt=mx=0;
        MemC(ans);
        MemC(tmp);
        while (1) {
            scanf("%s",s);
            if (strcmp(s, "0")==0) {
                break;
            }
            l=strlen(s);
            mx=max(l, mx);
            for (int i=0; i<l; i++)
                tmp[cnt][i]=s[l-1-i]-'0';
            cnt++;
        }
        if (cnt==0) {
            printf("0\n");
            goto label;
        }

        for (int i=0; i<mx; i++) {
            for (int j=0; j<cnt; j++) {
                ans[i]+=tmp[j][i];
            }
            ans[i+1]=ans[i]/10;
            ans[i]%=10;
            ans[i]+='0';
        }
        ans[mx]+='0';
        for (int i=mx; i>=0; i--) {
            if (i==mx&&ans[i]=='0') {
                continue;
            }
            else{
                pf("%c",ans[i]);
            }
        }
        pf("\n");
label:   if (t!=0) {
            pf("\n");
        }
    }
}