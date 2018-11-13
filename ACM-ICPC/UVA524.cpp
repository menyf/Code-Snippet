// Wrote by MenYifan on 2015-12-18 09:43:23
// Exe.Time 106ms Exe.Memory 0K
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
int vis[50];
int n,pos;
int g[32][32];
int head[32];
int ans[32];
int isPrime(int num)
{
    if(1 == num || 0 == num)
        return 0;
    int s,t;
    s = sqrt(num);
    for (t = 2; t <= s; t++)
        if (num%t==0) break;
    if (t >= s + 1) return 1;
    else return 0;
}
void init(){
    memset(g, 0, sizeof(g));
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    vis[1]=0;
    pos=2;
    
    int index;
    for (int i=1; i<=n; i++) {
        index=1;
        for (int j=1; j<=n; j++) {
            if (i!=j&&isPrime(i+j)) {
                g[i][index++]=j;
            }
        }
        head[i]=index;
    }
}
void showans(){
    for (int i=1; i<=n; i++) {
        printf("%d",ans[i]);
        if (i!=n) {
            printf(" ");
        }
        else
            printf("\n");
    }
}
void dfs(int x,int moves){
    vis[x]=1;
    ans[moves]=x;
    if (moves==n&&isPrime(x+1))
        showans();
    for (int i=1; i<head[x]; i++) {
        int tmp=g[x][i];
        if (vis[tmp]==0) {
            dfs(tmp, moves+1);
        }
    }
    vis[x]=0;
}
int main(){
    bool flag=false;
    int cas=1;
    while (scanf("%d",&n)!=EOF) {
        if (flag) printf("\n");
        printf("Case %d:\n",cas++);
        init();
        dfs(1, 1);
        flag=true;
    }
    return 0;
}