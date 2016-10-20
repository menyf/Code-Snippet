// Wrote by MenYifan on 2015-04-17 21:33:54
// Exe.Time 31ms Exe.Memory 1992K
//
//  20150417c.cpp
//  Cfiles
//
//  Created by ??? on 15/4/17.
//  Copyright (c) 2015? ???. All rights reserved.
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
#define MAX 1000
#define inf 99999999
int path[MAX][MAX]={};
int n,m;
void init (){
    int i, j;
    for (i = 0; i <= n; i++)    //i==j??????????0?????????
        for (j = 0; j <= n; j++)
            path[i][j] = inf;
}
void floyd(){
    int i,j,k;
    for (k=0; k<n; k++) {
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                if (path[i][k]!=inf&&path[k][j]!=inf&&path[i][k]+path[k][j]<path[i][j]) {
                    path[i][j]=path[i][k]+path[k][j];
                }
            }
        }
    }
}

int main(){
    int x,y,d;
    while (scanf("%d %d",&n,&m)!=EOF) {
        init();
        while (m--) {
            scanf("%d %d %d",&x,&y,&d);
            if (d<path[x][y]) {
                path[x][y]=path[y][x]=d;
            }
        }
        floyd();
        
        scanf("%d %d",&x,&y);
        if (x==y){
            cout<<"0"<<endl;
        }
        else if (path[x][y]!=inf) {
            cout<<path[x][y]<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
}