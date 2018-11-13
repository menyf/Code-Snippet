// Wrote by MenYifan on 2015-08-04 10:11:39
// Exe.Time 70ms Exe.Memory 26824K
//
//  20150803j.cpp
//  Cfiles
//
//  Created by ??? on 15/8/4.
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
#define maxn 2605
int xN,yN,gx[55][55],gy[55][55];
int mp[maxn][maxn],flag[maxn],link[maxn];
int dfs(int x){
    for (int i=1; i<=yN; i++) {
        if (mp[x][i]&&!flag[i]) {
            flag[i]=1;
            if (link[i]==-1||dfs(link[i])) {
                link[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(){
    int rt=0;
    vset(link, -1);
    for (int i=1; i<=xN; i++) {
        vset(flag, 0);
        rt+=dfs(i);
    }
    return rt;
}
int main(){
    char s[55][55];
    int t;
    sf(t);
    for(int cas=1;cas<=t;cas++) {
        xN=yN=0;
        vset(mp, 0);
        vset(gx, 0);
        vset(gy, 0);
        
        int r,c;
        sff(r, c);
        for (int i=0; i<r; i++)
            scanf("%s",s[i]);
        
        for (int i=0; i<r; i++) {
            bool flag=true;
            for (int j=0; j<c; j++) {
                if (s[i][j]=='o') {
                    if (flag) {
                        xN++;
                        flag=false;
                    }
                    gx[i][j]=xN;
                }
                else if (s[i][j]=='#'){
                    flag=true;
                }
            }
        }
        
        for (int i=0; i<c; i++) {
            bool flag=true;
            for (int j=0; j<r; j++) {
                if (s[j][i]=='o') {
                    if (flag) {
                        yN++;
                        flag=false;
                    }
                    gy[j][i]=yN;
                }
                else if (s[j][i]=='#')
                    flag=true;
            }
        }
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (gx[i][j]&&gy[i][j]) {
                    mp[gx[i][j]][gy[i][j]]=1;
                }
            }
        }
        
        pf("Case :%d\n%d\n",cas,hungary());
//        cout<<hungary()<<endl;
    }
}