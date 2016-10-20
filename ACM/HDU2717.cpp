// Wrote by MenYifan on 2015-12-13 22:22:07
// Exe.Time 15ms Exe.Memory 2500K
//
//  20151213h.cpp
//  Cfiles
//
//  Created by ??? on 15/12/13.
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
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 200005

int vis[maxn];
int a,b;
void bfs(){
    Memset(vis, 0);
    queue<int>q;
    q.push(a);
    vis[a]=1;
    while (!q.empty()) {
        int tp=q.front();
        q.pop();
        if (tp<b) {
            if (tp+1<maxn&&!vis[tp+1]) {
                vis[tp+1]=vis[tp]+1;
                if (tp+1==b) return;
                else q.push(tp+1);
            }
            if (tp*2<maxn&&!vis[tp*2]) {
                vis[2*tp]=vis[tp]+1;
                if (tp*2==b) return;
                else q.push(2*tp);
            }
        }
        if (tp-1>=0&&!vis[tp-1]) {
            vis[tp-1]=vis[tp]+1;
            if (tp-1==b) return;
            else q.push(tp-1);
        }
        
    }
}
int main(){
    while (scanf("%d%d",&a,&b)!=EOF) {
        bfs();
        printf("%d\n",vis[b]-1);
    }
}