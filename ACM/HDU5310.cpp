//
//  1stAnniversaryA.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/7/25.
//  Copyright (c) 2015年 门一凡. All rights reserved.
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
    int t;
    sf(t);
    while (t--) {
        int n,m,q,tmp,p,ans=0;
        cin>>n>>m>>p>>q;
//        scanf("%d%d%d%d",&n,&m,&p,&q);
        double a;
        a=1.0*q/m;
        if (a>p) {
            ans=n*p;
        }
        else{
            ans=(n/m)*q;
            tmp=n/m;
            tmp*=m;
            n-=tmp;
            if (n*p<q) {
                ans+=n*p;
            }
            else
                ans+=q;
        }
        printf("%d\n",ans);
        
    }
}
