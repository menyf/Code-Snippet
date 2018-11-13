#include <stdio.h>
#include "cstring"
#include "iostream"
using namespace std;
int m,n;//m是行数 n是列数
int vis[150][150]={};
int r[]={1,1,1,0,0,-1,-1,-1};
int c[]={-1,0,1,-1,1,0,1,-1};
char map[150][150];
int inmap(int y,int x){
    return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int j,int i){
    if (vis[j][i]==1) {
        return;
    }
    vis[j][i]=1;
    for (int p=0; p<8; p++) {
        if (inmap(j+r[p], i+c[p])&&map[j+r[p]][i+c[p]]=='@') {
            dfs(j+r[p],i+c[p]);
        }
        
    }
}
int main(){
    scanf("%d%d",&m,&n);
    while (m!=0) {
        int t=0;
        for (int i=0; i<m; i++) {
            scanf("%s",map[i]);
        }
        for (int j=0; j<m; j++) {
            for (int i=0; i<n; i++) {
                if (vis[j][i]==0&&map[j][i]=='@') {
                    dfs(j,i);
                    t++;
                }
            }
        }
        printf("%d\n",t);
        memset(vis, 0, sizeof(vis));
        memset(map, '\0', sizeof(map));
            scanf("%d%d",&m,&n);
    }
    
}
