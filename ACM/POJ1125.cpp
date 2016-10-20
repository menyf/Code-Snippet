//
//  POJ1125dijkstra+并查集.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/8/15.
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
#define INF 99999
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int bin[105];
int dis[105];
int mp[105][105];
bool vis[105];
int dijkstra(int n,int s){
    int ans=0;
    for (int i=0; i<=n; i++) {
        dis[i]=INF;
        vis[i]=false;
    }
    dis[s]=0;
    
    for (int i=1; i<=n; i++) {
        int pos=0;
        for (int j=1; j<=n; j++) {
            if (!vis[j]&&dis[j]<dis[pos]) {
                pos=j;
            }
        }
        vis[pos]=true;
        for (int j=1; j<=n; j++) {
            if (mp[pos][j]!=INF&&!vis[j]&&dis[pos]+mp[pos][j]<dis[j]) {
                dis[j]=dis[pos]+mp[pos][j];
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (ans<dis[i]) {
            ans=dis[i];
        }
    }
    
    return ans;
}
int findx(int x){
    while (x!=bin[x]) {
        x=bin[x];
    }
    return x;
}
void set_merge(int a,int b){
    if ((a=findx(a))!=(b=findx(b)))
        bin[a]=b;
}
int main(){
    int n,m,p,t;
    while (sf(n),n) {
        int ansp=0,ansd=INF;
        int flag=0;
        for (int i=0; i<=n; i++)
            bin[i]=i;
        
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                mp[i][j]=i!=j?INF:0;
            }
        }
        
        for (int i=1; i<=n; i++) {
            sf(m);
            while (m--) {
                sff(p, t);
                mp[i][p]=t;
                set_merge(i, p);
            }
        }
        
        for (int i=1; i<=n; i++) {
            if (bin[i]==i) {
                flag++;
            }
        }

        if (flag>1) {
            puts("disjoint");
            continue;
        }
        
        for (int i=1; i<=n; i++) {
            int tmp=dijkstra(n,i);
            if (tmp<ansd) {
                ansd=tmp;
                ansp=i;
            }
        }
        cout<<ansp<<" "<<ansd<<endl;
    }
}
