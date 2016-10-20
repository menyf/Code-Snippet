// Wrote by MenYifan on 2015-07-30 15:35:53
// Exe.Time 30ms Exe.Memory 8K
//
//  20150730e.cpp
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
    int k,a,b,v,t,ans=0;
    scanf("%d%d%d%d",&k,&a,&b,&v);
    t=a/v;
    if (a%v!=0) t++;
    while (t>0) {
        if (b>=k-1) {//bar??
            t-=k;
            b-=k-1;
            ans++;
        }
        else{
            if (b!=0) {
                t-=(b+1);
                b=0;
//                bug;
//                cout<<t<<endl;
                ans++;
            }
            else{
                t-=1;
                ans++;
            }
        }
//        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    
    
    
}