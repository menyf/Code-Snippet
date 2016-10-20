// Wrote by MenYifan on 2015-07-14 21:38:32
// Exe.Time 92ms Exe.Memory 776K
//
//  20150714c.cpp
//  Cfiles
//
//  Created by ??? on 15/7/14.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,t=1,mx=0,tree[100050]={},dis[100050]={};//t?????? mx???????t???
    cin>>n;
    for (int i=1; i<=n; i++)
        scanf("%d",tree+i);
    t=n/2+n%2;
    
    for (int i=1; i<=t; i++) {
        if (tree[i]-i+1>0) {
            dis[tree[i]-i+1]++;
            //??????????????
        }
    }
    for (int i=n; i>t; i--) {
        if (tree[i]+i-n>0) {
            dis[tree[i]+i-n]++;
            //??????????????
        }
    }
    for (int i=0; i<100050; i++) {
        mx=max(dis[i],mx);
        //??????????
    }
    cout<<n-mx<<endl;
}