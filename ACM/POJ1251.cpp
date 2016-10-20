//
//  20150511e.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/5/11.
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
#define MX 105
#define inf 9999999
int main(){
    int i,M,j,min;
    while (scanf("%d",&M),M) {
        char ch1[2],ch2[2];
        int path[105][105]={};
        memset(path, inf, sizeof(path));
        int vis[105]={};
        int dis[105]={};
        int d,pos,ans=0,t;
        
        for (j=0; j<M-1; j++) {
            scanf("%s%d",ch1,&t);
            for (i=0; i<t; i++) {
                scanf("%s%d",ch2,&d);
                path[ch1[0]-64][ch2[0]-64]=path[ch2[0]-64][ch1[0]-64]=d;
            }
        }

        vis[1]=1;
        pos=1;
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
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
