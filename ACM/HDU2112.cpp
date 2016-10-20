// Wrote by MenYifan on 2015-08-13 21:09:27
// Exe.Time 3088ms Exe.Memory 1772K
//
//  2122dijkstra.cpp
//  Cfiles
//
//  Created by ??? on 15/8/13.
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
#define inf 9999999
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 160
map<string, int> m;
int id,d;
int mp[maxn][maxn];
int dis[maxn];
bool vis[maxn],flag;//flag???????????
void init(int n){
    memset(vis, false, sizeof(vis));
    m.clear();
    id=0;
    flag=true;
    for (int i=0; i<maxn; i++)
        dis[i]=inf;
    dis[1]=0;
    for (int i=0; i<maxn; i++)
        for (int j=0; j<maxn; j++)
            mp[i][j]=i!=j?inf:0;
    string s1,s2;
    cin>>s1>>s2;
    if (s1==s2)
        flag=false;
    m[s1]=++id;
    m[s2]=++id;
    for (int i=0; i<n; i++) {
        cin>>s1>>s2>>d;
        if (m.find(s1)==m.end())
            m[s1]=++id;
        if (m.find(s2)==m.end())
            m[s2]=++id;
        mp[m[s1]][m[s2]]=mp[m[s2]][m[s1]]=d;
    }
}
void dijkstra(){
    for (int i=1; i<=id; i++) {
        int pos=0;
        for (int j=1; j<=id; j++) {
            if (!vis[j]&&dis[j]<dis[pos]) {
                pos=j;
            }
        }
        vis[pos]=true;
        for (int j=1; j<=id; j++)
            if (mp[pos][j]!=inf&&!vis[j]&&dis[pos]+mp[pos][j]<dis[j])
                dis[j]=dis[pos]+mp[pos][j];
    }
}
int main(){
    int n;
    while (scanf("%d",&n)&&~n) {
        init(n);
        if (!flag) {
            cout<<0<<endl;
            continue;
        }
        dijkstra();
        if (dis[2]==inf) {
            cout<<-1<<endl;
        }
        else
            cout<<dis[2]<<endl;
    }
}