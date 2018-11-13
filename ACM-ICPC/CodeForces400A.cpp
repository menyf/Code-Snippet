// Wrote by MenYifan on 2015-07-30 15:04:32
// Exe.Time 31ms Exe.Memory 4K
//
//  20150730a.cpp
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
#define maxn 10005
int main(){
    char s[15];
    int n,ans,i,j,k,a[6],cnt;
    int x[]={1,2,3,4,6,12};
    int y[]={12,6,4,3,2,1};
    sf(n);
    while (n--) {
        MemI(a);
        ans=0;
        scanf("%s",s);
        for (i=0; i<6; i++) {
            for (j=0; j<y[i]; j++) {
                cnt=0;
                for (k=j; k<12; k+=y[i]) {
                    if (s[k]=='X') {
                        cnt++;
                    }
                    else
                        break;
                }
                if (cnt==x[i]) {
                    a[i]=1;
                    ans++;
                    break;
                }
            }
        }
        cout<<ans;
        for (int i=0; i<6; i++) {
            if (a[i]) {
                printf(" %dx%d",x[i],y[i]);
            }
        }
        puts("");
    }
}