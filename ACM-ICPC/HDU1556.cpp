// Wrote by MenYifan on 2015-05-16 19:37:07
// Exe.Time 546ms Exe.Memory 1984K
//
//  20150515b.cpp
//  Cfiles
//
//  Created by ??? on 15/5/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace std;
#define MAX 100005
int ball[MAX],N,a,b;
int lowbit(int x){
    return x&(-x);
}
void update(int pos,int val){
    while (pos<=N) {
        ball[pos]+=val;
        pos+=lowbit(pos);
    }
}
int sum(int pos){
    int ans=0;
    while (pos>0) {
        ans+=ball[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    while (scanf("%d",&N),N) {
        memset(ball, 0, sizeof(ball));
        for (int i=0; i<N; i++) {
            scanf("%d %d",&a,&b);
            update(a,1);
            update(b+1,-1);
        }
        for (int i=1; i<=N; i++) {
            cout<<sum(i);
            i!=N?cout<<" ":cout<<endl;
        }
    }
}
