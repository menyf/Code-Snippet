// Wrote by MenYifan on 2015-04-10 22:33:25
// Exe.Time 110ms Exe.Memory 996K
//
//  20150410e.cpp
//  Cfiles
//
//  Created by ??? on 15/4/10.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[40050];
int vis[40050];
int dp(int a[],int n){
    int len=1;
    memset(vis, 0, sizeof(vis));
    vis[0]=-1;
    vis[1]=a[0];
    for (int i=0; i<n; i++) {
        if (vis[len]<a[i]) vis[++len]=a[i];
        else {
            int mid,left=1,right=len;
            while(left<=right) {
                mid=(left+right)/2;
                if (vis[mid]>a[i]) right=mid-1;
                else left=mid+1;
            }
            vis[left]=a[i];
        }
    }
    return len;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",a+i);
        }
        printf("%d\n",dp(a,n));
    }
    return 0;
}