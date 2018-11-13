// Wrote by MenYifan on 2015-03-22 20:37:58
// Exe.Time 62ms Exe.Memory 0K
//
//  20150322f.cpp
//  Cfiles
//
//  Created by ??? on 15/3/22.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
int l[3][3];

int inmap(int y,int x){
    return x>=0&&x<=2&&y>=0&&y<=2;
}
int f(int a){
    if (a==0) {
        return 1;
    }
    else
        return 0;
}
int main(){
    int h[]={0,0,0,-1,1};
    int v[]={0,1,-1,0,0};

    for (int i=0; i<9; i++) {
        *(*l+i)=1;
    }
    
    int m;
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            scanf("%d",&m);
            if (m%2) {
                    for (int t=0; t<5; t++) {
                    if (inmap(j+v[t], i+h[t])) {
                        l[j+v[t]][i+h[t]]=f(l[j+v[t]][i+h[t]]);
                    }
                }
            }
        }
    }
    
    for (int i=0; i<9; i++) {
        if (i%3==0&&i!=0) {
            printf("\n");
        }
        printf("%d",*(*l+i));
    }
}