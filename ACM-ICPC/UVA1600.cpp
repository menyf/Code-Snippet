// Wrote by MenYifan on 2015-11-09 00:56:18
// Exe.Time 0ms Exe.Memory 0K
//
//  20151108c.cpp
//  Cfiles
//
//  Created by ??? on 15/11/8.
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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int mp[30][30];
int vis[30][30][50];
int mx[]={-1,1,0,0};
int my[]={0,0,-1,1};
int n,m,k,t;
struct point{
    //????????????????????????
    int x,y,moves,z;
    point(){}
    point(int a,int b,int c,int d){
        x=a;
        y=b;
        moves=c;
        z=d;
    }
};
bool inmap(int x,int y){
    return x>0&&y>0&&x<=m&&y<=n;
}
void bfs(){
    memset(vis, INF, sizeof(vis));
    point a(1,1,0,0);
    queue<point>q;
    q.push(a);
    vis[a.x][a.y][0]=0;
    while (!q.empty()) {
        point tmp=q.front();
        q.pop();
        
        if (vis[tmp.x][tmp.y][tmp.z]<tmp.moves)
            continue;
        
        if (tmp.x==m&&tmp.y==n) {
            printf("%d\n",tmp.moves);
            return;
        }
        
        point tp;
        for (int i=0; i<4; i++) {
            tp.x=tmp.x+mx[i];
            tp.y=tmp.y+my[i];
            tp.moves=tmp.moves+1;
            
            if (tmp.z==k&&mp[tp.x][tp.y]==1)    //??????k???????
                continue;
            else if (mp[tp.x][tp.y]==1) //????
                tp.z=tmp.z+1;
            else    //?????????
                tp.z=0;
            
            //????????????z???????????????vis[][][]
            if (inmap(tp.x, tp.y)&&vis[tp.x][tp.y][tp.z]>tp.moves) {
                vis[tp.x][tp.y][tp.z]=tp.moves;
                q.push(tp);
            }
        }
    }
    printf("-1\n");
    return;
}
int main(){
    scanf("%d",&t);
    for (int cas=0; cas<t; cas++) {
        memset(mp, 0, sizeof(mp));
        scanf("%d%d%d",&m,&n,&k);
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                scanf("%d",&mp[i][j]);
        bfs();
    }
}