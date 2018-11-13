// Wrote by MenYifan on 2015-04-13 00:04:18
// Exe.Time 31ms Exe.Memory 4K
//
//  20150412f.cpp
//  Cfiles
//
//  Created by ??? on 15/4/12.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    int b[105]={},g[105]={};
    int cb=0,cg=0,tmp=0;
    int n,cnt=0;
    
    scanf("%d %d",&cb,&cg);
    
    scanf("%d",&n);
    cnt+=n;
    for (int i=0; i<n; i++) {
        scanf("%d",&tmp);
        b[tmp]=1;
    }
    scanf("%d",&n);
    cnt+=n;
    for (int i=0; i<n; i++) {
        scanf("%d",&tmp);
        g[tmp]=1;
    }
    
    int cnt0=-1,i=0,max;
    
    if (cb>cg) {
        max=cb;
    }
    else
        max=cg;
    
    while (i<2*cg*cb) {
      /*  if (i%(max)==0) {
            cnt0=cnt;
        }
      */
        int x,y;
        x=i%cb;
        y=i%cg;
        if (b[x]==1&&g[y]==0) {
            g[y]=1;
            cnt++;
        }
        if (b[x]==0&&g[y]==1) {
            b[x]=1;
            cnt++;
        }
        i++;
    }
    
    
    if (cnt==cb+cg) {
        printf("Yes");
    }
    else
        printf("No");
}