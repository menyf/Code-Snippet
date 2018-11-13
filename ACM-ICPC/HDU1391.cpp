// Wrote by MenYifan on 2015-03-15 21:16:12
// Exe.Time 0ms Exe.Memory 1616K
//
//  20150315g.cpp
//  Cfiles
//
//  Created by ??? on 15/3/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include "algorithm"
#include <stdlib.h>
#include "ctype.h"
#include <iostream>
#include "string.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        if (y==x) {
            if (x%2==0) {
                printf("%d",2*x);
            }
            else
                printf("%d",2*x-1);
        }
        else if (y==x-2){
            if (x%2==1) {
                printf("%d",2*x-3);
            }
            else
                printf("%d",2*x-2);
        }
        else{
            printf("No Number");
        }
            printf("\n");
        
    }
    

}