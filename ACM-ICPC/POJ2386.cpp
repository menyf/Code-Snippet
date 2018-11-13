#include <stdio.h>
#include "cstdlib"
#include "iostream"
using namespace std;
char s[105][105];
int vis[105][105]={};
int m,n;
int go(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int x,int y)
{
    if (vis[x][y]) {
        return;
    }
    vis[x][y]=1;
    if (go(x-1, y+1)&&s[x-1][y+1]=='W') {
        dfs(x-1, y+1);
    }
    if (go(x-1, y)&&s[x-1][y]=='W') {
        dfs(x-1, y);
    }
    if (go(x-1, y-1)&&s[x-1][y-1]=='W') {
        dfs(x-1, y-1);
    }
    if (go(x, y+1)&&s[x][y+1]=='W') {
        dfs(x, y+1);
    }
    if (go(x, y-1)&&s[x][y-1]=='W') {
        dfs(x, y-1);
    }
    if (go(x+1, y+1)&&s[x+1][y+1]=='W') {
        dfs(x+1, y+1);
    }
    if (go(x+1, y)&&s[x+1][y]=='W') {
        dfs(x+1, y);
    }
    if (go(x+1, y-1)&&s[x+1][y-1]=='W') {
        dfs(x+1, y-1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%s",s[i]);
    }
    int a=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j]=='W'&&vis[i][j]==0) {
                dfs(i,j);
                a++;
            }
        }
    }
    printf("%d\n",a);
}
