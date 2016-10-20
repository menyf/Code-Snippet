//
//  20150511b.cpp
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
#define MAX 10050
#define inf 9999999
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int T,M,i,j;
    cin>>T;
    while (T--) {
        cin>>M;
        double coordinate[105][2];
        double path[105][105]={};
        int vis[105]={};
        double dis[105]={};
        int pos;
        double min,ans=0;
        memset(path, inf, sizeof(path));
        
        for (i=1; i<=M; i++) {
            cin>>coordinate[i][0]>>coordinate[i][1];
        }
        
        for (i=1; i<=M; i++) {
            for (j=1; j<=M; j++) {
                path[i][j]=dist(coordinate[i][0], coordinate[i][1], coordinate[j][0], coordinate[j][1]);
                if (path[i][j]<10||path[i][j]>1000) {
                    path[i][j]=inf;
                }
            }
        }
        
        //核心代码
        //***********************************
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
            
            if (min==inf) {
                printf("oh!\n");
                break;
            }
            
            vis[pos]=1;
            ans+=min;
            
            for (j=1; j<=M; j++) {
                if (vis[j]==0&&path[pos][j]<dis[j]) {
                    dis[j]=path[pos][j];
                }
            }
            if (i==M-1) {
                printf("%.1lf\n",ans*100);
            }
        }
        //***********************************
    }
    
    
}
