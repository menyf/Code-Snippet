// Wrote by MenYifan on 2015-04-15 18:56:00
// Exe.Time 46ms Exe.Memory 4336K
//
//  20150415c.cpp
//  Cfiles
//
//  Created by ??? on 15/4/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 100050
int m,n,k;
int vis[1050][1050]={};
int mx[]={-1,-1,0,-1,-1,0,1,1,0,1,1,0};
int my[]={0,1,1,0,-1,-1,0,1,1,0,-1,-1};
int inmap(int y,int x){
    return x>=0&&y>=0&&x<m&&y<n;
}
int f(int y,int x){
    bool flag=false;
    int i=0;
    for (; i<12; i+=3) {
        if (inmap(y+my[i],x+mx[i])&&inmap(y+my[i+1],x+mx[i+1])&&inmap(y+my[i+2],x+mx[i+2])&&vis[y+my[i]][x+mx[i]]&&vis[y+my[i+1]][x+mx[i+1]]&&vis[y+my[i+2]][x+mx[i+2]]) {
            return 1;
        }
    }
    return 0;
}
int main(){
    cin>>n>>m>>k;
    int i;
    for (i=0; i<k; i++) {
        int x,y;
        scanf("%d %d",&y,&x);
        y--;
        x--;
        vis[y][x]=1;
        if (f(y, x)) {
            break;
        }
    }
    if (i==k) {
        printf("0");
    }
    else
        printf("%d",i+1);
}