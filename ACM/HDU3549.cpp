//
//  3549dinic.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/8/5.
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
#define maxn 10005
int vis[1000],dis[1000];
int cur[1000];
int st,ed,cnt;
int head[1000];
void init(){
    vset(cur, -1);
    vset(head, -1);
}
struct Edge
{
    int to,c,next;
}e[200000*2];
void add(int a,int b,int c)
{
    e[cnt].to=b;
    e[cnt].c=c;
    e[cnt].next=head[a];
    head[a]=cnt++;
    e[cnt].to=a;
    e[cnt].c=0;
    e[cnt].next=head[b];
    head[b]=cnt++;
}
bool BFS()
{
    memset(dis,-1,sizeof(dis));
    dis[st]=0;
    queue<int>que;
    que.push(st);
    while(!que.empty())
    {
        int j=que.front();
        que.pop();
        for(int k=head[j];k!=-1;k=e[k].next)
        {
            int i=e[k].to;
            if(dis[i]==-1&&e[k].c)
            {
                dis[i] = dis[j]+ 1 ;
                que.push(i);
                if(i==ed) return true;
            }
        }
    }
    return false;
}
int DFS(int x,int mx)
{
    if(x==ed || mx==0) return mx;
    int f,flow=0;
    for(int& i=cur[x];i!=-1;i=e[i].next)
    {
        if(dis[x]+1==dis[e[i].to] && (f=DFS(e[i].to,min(mx,e[i].c))))
        {
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            mx-=f;
            if(!mx)break;
        }
    }
    return flow;
}
int dinic(){
    int tmp=0;
    int maxflow=0;
    while(BFS())
    {
        for(int i=st;i<=ed;i++) cur[i]=head[i];
        while(tmp=DFS(st,INF)) maxflow+=tmp;
    }
    return maxflow;
}
//以上为dinic模板
int main()
{
    int t;
    sf(t);
    for (int cas=1; cas<=t; cas++) {
        init();
        int n,m,x,y,c;
        sff(n, m);
        st=1;ed=n;cnt=0;
        while (m--) {
            sfff(x, y, c);
            add(x, y, c);
        }
        printf("Case %d: %d\n",cas,dinic());
        
//        cout<<dinic()<<endl;
    }
    return 0;
}
