//
//  20150803f.cpp
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
#define maxn 1005
int mp[1050][1050],n,m;
int flag[maxn],link[maxn];
double dis(double x1,double y1,double x2,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int dfs(int pos){
    for (int i=1; i<=m; i++) {
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
int hungary(){
    int ans=0;
    vset(link, -1);
    for (int i=1; i<=n; i++) {
        vset(flag, 0);
        ans+=dfs(i);
    }
    return ans;
}
int main(){
    while(sff(n, m)!=EOF){
        vset(mp, 0);
        int s,v,p;
        scanf("%d%d",&s,&v);
        p=s*v;
        p*=p;
        double a[105]={},b[105]={};
        double x,y;
        
        for (int i=1; i<=n; i++)
            scanf("%lf%lf",a+i,b+i);
        
        for (int i=1; i<=m; i++) {
            scanf("%lf %lf",&x,&y);
            for (int j=1; j<=n; j++)
                if (dis(a[j], b[j], x, y)<=p)
                    mp[i][j]=1;
        }
        cout<<n-hungary()<<endl;
    }
}
