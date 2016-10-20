// Wrote by MenYifan on 2015-03-22 19:15:17
// Exe.Time 62ms Exe.Memory 0K
//
//  20150322a.cpp
//  Cfiles
//
//  Created by ??? on 15/3/22.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
int main(){
    int n,sum=0;
    scanf("%d",&n);
    int d[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&d[i]);
        sum+=d[i];
    }
    
    int s,e,dis=0;
    scanf("%d%d",&s,&e);
    
    if (s<e) {
        for (int i=s-1; i<e-1; i++) {
            dis+=d[i];
        }
        if (dis>sum/2) {
            printf("%d",sum-dis);
        }
        else
            printf("%d",dis);
    }
    else if(s>e){
        for (int i=e-1; i<s-1; i++) {
            dis+=d[i];
        }
        if (dis>sum/2) {
            printf("%d",sum-dis);
        }
        else
            printf("%d",dis);
    }
    else
        printf("0");
    
}