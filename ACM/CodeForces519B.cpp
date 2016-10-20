// Wrote by MenYifan on 2015-04-12 19:32:08
// Exe.Time 93ms Exe.Memory 1176K
//
//  20150314b.cpp
//  Cfiles
//
//  Created by ??? on 15/4/12.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100050
int main(){
    int n;
    scanf("%d",&n);
    int a[MAX],b[MAX],c[MAX];
    for (int i=0; i<n; i++) {
        scanf("%d",a+i);
    }
    for (int i=0; i<n-1; i++) {
        scanf("%d",b+i);
    }
    for (int i=0; i<n-2; i++) {
        scanf("%d",c+i);
    }
    
    sort(a,a+n);
    sort(b,b+n-1);
    sort(c,c+n-2);
    
    for (int i=0; i<n; i++) {
        if (i==n-1) {
            printf("%d\n",a[i]);
        }
        else if (a[i]!=b[i]) {
            printf("%d\n",a[i]);
          //  printf("a");
            break;
        }
    }
    
    for (int i=0; i<n-1; i++) {
        if (i==n-2) {
            printf("%d",b[i]);
        }
        else if (b[i]!=c[i]) {
            printf("%d\n",b[i]);
            break;
        }
    }
    return 0;
}
