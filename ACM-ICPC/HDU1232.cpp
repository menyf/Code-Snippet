// Wrote by MenYifan on 2015-04-03 19:57:41
// Exe.Time 31ms Exe.Memory 1580K
//
//  20150403a.cpp
//  Cfiles
//
//  Created by ??? on 15/4/3.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int city[1050];
int n,m;
int findx(int x){
    int r=x;
    while (city[r]!=r) {
        r=city[r];
    }
    return r;
    //?????????????
}
void merge1(int a,int b){
    //??????????????
    int fy,fx;
    fx=findx(a);
    fy=findx(b);
    if (fx!=fy) {
        city[fx]=fy;
        //?????????????????????????????????????????????????????????
    }
}
int main(){
    scanf("%d %d",&n,&m);//n??? m???
    while (n!=0) {
        int ini,fin,cnt=0;
        for (int i=1; i<=n; i++) {
            city[i]=i;
        }
        for (int i=0; i<m; i++) {
            scanf("%d%d",&ini,&fin);
            merge1(ini,fin);
        }
        for (int i=1; i<=n; i++) {
            if (city[i]==i) {
                cnt++;
            }
        }
        printf("%d\n",cnt-1);
        scanf("%d %d",&n,&m);
    }
}