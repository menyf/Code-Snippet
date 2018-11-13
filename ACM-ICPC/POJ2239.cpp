//
//  20150803e.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/8/3.
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
#define vset(a,val) memset(a,val,sizeof(a))
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
#define maxn 350
int mp[maxn][maxn]={};
int link[maxn],flag[maxn];
int n;
int dfs(int pos){
    for (int i=1; i<=7*12; i++) {
        if (mp[pos][i]&&!flag[i]) {
            flag[i]=1;
            if (link[i]==-1||dfs(link[i])) {
                link[i]=pos;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    while (sf(n)!=EOF) {
        int t,tmp1,tmp2,ans=0;
        vset(mp, 0);
        vset(link, -1);
        for (int i=1; i<=n; i++) {
            sf(t);
            for (int j=1; j<=t; j++) {
                sff(tmp1, tmp2);
                mp[i][12*(tmp1-1)+tmp2]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            vset(flag, 0);
            ans+=dfs(i);
        }
        cout<<ans<<endl;
    }
}
