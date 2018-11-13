//
//  20150511g.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/5/12.
//  Copyright (c) 2015年 门一凡. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 2005
#define inf 9999
int path[MAX][MAX]={};
int vis[MAX]={};
int dis[MAX]={};
int main(){
    int M,i,j,k,pos,ans,min;
    while (scanf("%d",&M),M) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        memset(path, 0, sizeof(path));
        char s[2005][10];
        for (i=1; i<=M; i++) {
            cin>>s[i];
        }
        
        //路径输入
        for (i=1; i<=M; i++) {
            for (j=1; j<=M; j++) {
                for (k=0; k<7; k++) {
                    if (s[i][k]!=s[j][k]) {
                        path[i][j]++;
                    }
                }
            }
        }
        
        //prim核心代码
        vis[1]=1;
        pos=1;
        ans=0;
        for (i=2; i<=M; i++) {
            dis[i]=path[1][i];
        }
        
        for (i=1; i<M; i++) {
            min=inf;
            for (j=1; j<=M; j++) {
                if (dis[j]<min&&vis[j]==0) {
                    min=dis[j];
                    pos=j;
                }
            }
            
            vis[pos]=1;
            ans+=min;
            
            for (j=1; j<=M; j++) {
                if (vis[j]==0&&path[pos][j]<dis[j]) {
                    dis[j]=path[pos][j];
                }
            }
            
            if (i==M-1) {
                if (ans==1) {
                    printf("The highest possible quality is 1.\n");
                }
                else
                    printf("The highest possible quality is 1/%d.\n",ans);
            }
        }
        
    }
    
    
    return 0;
}
