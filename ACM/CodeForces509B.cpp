// Wrote by MenYifan on 2015-04-15 18:32:02
// Exe.Time 30ms Exe.Memory 4K
//
//  20150415b.cpp
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
int main(){
    int n,c,max=0,min;
    cin>>n>>c;
    int a[105]={};
    for (int i=0; i<n; i++) {
        cin>>a[i];
        if (i==0) {
            min=a[i];
        }
        if (max<a[i]) {
            max=a[i];
        }
        if (min>a[i]) {
            min=a[i];
        }
    }
    if (max-min>c) {
        printf("NO");
    }
    else{
        printf("YES\n");
        for (int i=0; i<n; i++) {
            int t=1;
            for (int j=0; j<a[i]; j++) {
                if (t>c) {
                    t-=c;
                }
                printf("%d",t++);
                if (j!=a[i]-1) {
                    printf(" ");
                }
                else
                    printf("\n");
            }
        }
    }
    
}
