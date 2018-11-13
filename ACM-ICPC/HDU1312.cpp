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
#define maxn 10005
int w,h,ans;
int vis[25][25];
char mp[25][25];
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};
void init(){
    //初始化+输入
    Memset(vis, 0);
    Memset(mp, 0);
    ans=0;
    for (int i=1; i<=h; i++)
        scanf("%s",mp[i]+1);
}
void dfs(int x,int y){
    ans++;
    for (int i=0; i<4; i++) {
        int tx=x+mx[i];
        int ty=y+my[i];
        if (vis[tx][ty]==0&&mp[tx][ty]=='.') {
            vis[tx][ty]=1;
            dfs(tx, ty);
        }
    }
}
void work(){
    //找DFS的起点
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            if (mp[i][j]=='@') {
                vis[i][j]=1;
                dfs(i,j);
                return;
            }
        }
    }
}
int main(){
    while (scanf("%d %d",&w,&h),w&&h) {
        init();
        work();
        printf("%d\n",ans);
    }
}
