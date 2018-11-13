// Wrote by MenYifan on 2015-04-10 21:04:49
// Exe.Time 188ms Exe.Memory 468K
//
//  20150410i.cpp
//  Cfiles
//
//  Created by ??? on 15/4/10.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <string.h>
using namespace std;
int f[35000];
int c[35000];
int w[35000];
int main(){
    int N,V;
    scanf("%d %d",&N,&V);
    for (int i=1; i <= N; ++i)
    {
        scanf("%d %d",&c[i],&w[i]);
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int v = V; v >= c[i]; --v)
        {
            if(f[v] <= f[v - c[i]] + w[i])
            {
                f[v] = f[v - c[i]] + w[i];
            }
        }
    }
    printf("%d",f[V]);
    return 0;
}