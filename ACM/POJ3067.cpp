//
//  20150515d.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/5/17.
//  Copyright (c) 2015年 门一凡. All rights reserved.
//  逆序数
//  树状数组

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "cstring"
using namespace std;
#define MAX 1005
int n,m,k;
long long c[MAX];
struct Node{
    long long x,y;
}l[MAX*MAX];
int lowbit(int x){
    return x&(-x);
}
void update(long long pos,long long val){
    while (pos<=MAX) {//可能的错误：此处n 改为max
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
long long sum(long long pos){
    long long ans=0;
    while (pos>0) {
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int cmp(Node a,Node b){
    return a.x==b.x?(a.y<b.y):(a.x<b.x);
}
int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++) {
        scanf("%d %d %d",&n,&m,&k);
        memset(c, 0, sizeof(c));
        for (int i=1; i<=k; i++) {
            scanf("%lld %lld",&l[i].x,&l[i].y);
        }
        sort(l+1, l+1+k, cmp);
        long long ans=0;
        for(int i=1;i<=k;i++){
            update(l[i].y,1);
            ans+=i-sum(l[i].y);
        }
         printf("Test case %d: %I64d\n",t+1,ans);
    }
    
}
