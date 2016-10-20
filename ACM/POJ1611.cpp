// Wrote by MenYifan on 2015-04-03 21:40:18
// Exe.Time 16ms Exe.Memory 792K
//
//  20150403.2a.cpp
//  Cfiles
//
//  Created by ??? on 15/4/3.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int s[30050];
int findx(int x){
    int r=x;
    while (s[r]!=r) {
        r=s[r];
    }
    return r;
}
void merge1(int a,int b){
    int fx,fy;
    fx=findx(a);
    fy=findx(b);
    if (fx<fy) {
        s[fy]=fx;
    }
    else
        s[fx]=fy;
}
int main(){
    int m,n,x,y,t;
    scanf("%d %d",&n,&m);
    while (!(n==0&&m==0)) {
        for (int i=0; i<n; i++) {
            s[i]=i;
        }
        for (int i=0; i<m; i++) {
            scanf("%d",&t);
            scanf("%d",&x);
            for (int j=0; j<t-1; j++) {
                scanf("%d",&y);
                merge1(x, y);
            }
        }
        int cnt=0;
        for (int i=0; i<n; i++) {
            if (findx(i)==0) {
                cnt++;
            }
        }
        printf("%d\n",cnt);
        scanf("%d %d",&n,&m);
    }
}