// Wrote by MenYifan on 2015-10-07 21:12:36
// Exe.Time 36ms Exe.Memory 0K
//
//  20151007g.cpp
//  Cfiles
//
//  Created by ??? on 15/10/7.
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
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 100005
int main(){
    int n,s,ans;
    int num[maxn],sum[maxn];
    while (sff(n, s)!=EOF) {
        ans=n;
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        
        for (int i=0; i<n; i++) {
            scanf("%d",&num[i]);
            if (i==0)
                sum[i]=num[i];
            else
                sum[i]=sum[i-1]+num[i];
        }
        
//        for (int i=0; i<n; i++) {
//            printf("%3d ",sum[i]);
//        }
        
        for (int i=0; sum[i]+s<=sum[n-1]; i++) {
            int pos=lower_bound(sum, sum+n, sum[i]+s)-sum;
            ans=min(ans, pos-i);
        }
        if (ans!=n) {
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;
        }
        
    }
}
/*
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5


*/