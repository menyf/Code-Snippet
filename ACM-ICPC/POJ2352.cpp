// Wrote by MenYifan on 2015-05-17 10:08:46
// Exe.Time 235ms Exe.Memory 892K
//
//  20150515c.cpp
//  Cfiles
//
//  Created by ??? on 15/5/17.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 32005
int c[MAX]={},n,x,y,l[MAX]={};
int lowbit(int x){
    return x&(-x);
}
void update(int pos,int val){
    while (pos<=MAX) {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
int sum(int pos){
    int ans=0;
    while (pos>0) {
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    cin>>n;
    for (int i=1; i<=n; i++) {
        scanf("%d %d",&x,&y);
        l[sum(x+1)]++;
        update(x+1, 1);
    }
    for (int i=0; i<n; i++) {
        cout<<l[i]<<endl;
    }
}