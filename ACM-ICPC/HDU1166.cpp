// Wrote by MenYifan on 2015-05-16 19:11:24
// Exe.Time 780ms Exe.Memory 1808K
//
//  20150515a.cpp
//  Cfiles
//
//  Created by ??? on 15/5/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;
#define MAX 50005
int a[MAX],N;
int lowbit(int x){
    return x&(-x);
}
void update(int pos,int val){
    while (pos<=N) {
        a[pos]+=val;
        pos+=lowbit(pos);
    }
}
int sum(int pos){
    int ans=0;
    while (pos>0) {
        ans+=a[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    int T,t=0,i,j,tmp;
    cin>>T;
    for (; t<T; t++) {
        memset(a, 0, sizeof(a));
        cin>>N;
        for (i=0; i<N; i++) {
            scanf("%d",&tmp);
            update(i+1, tmp);
        }
        string s;
        printf("Case %d:\n",t+1);
        while (1) {
            cin>>s;
            if (s=="Add") {
                scanf("%d %d",&i,&j);
                update(i, j);
            }
            else if (s=="Sub"){
                scanf("%d %d",&i,&j);
                update(i, -j);
            }
            else if (s=="Query"){
                scanf("%d %d",&i,&j);
                printf("%d\n",sum(j)-sum(i-1));
            }
            else if (s=="End"){
                break;
            }
        }
    }
    return 0;
}