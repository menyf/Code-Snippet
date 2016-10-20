//
//  RMQ.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/7/30.
//  Copyright (c) 2015年 门一凡. All rights reserved.
//  hdu1754 I Hate It
//  RMQ:Range Minimum(Maximum) Query
//  该题查询最大值，最小值同理

#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 200000+5
#define RMQ max
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[maxn<<2]={};
void pushup(int rt){
    sum[rt]=RMQ(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt=1){
    if (l==r){
        scanf("%d",sum+rt);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int pos,int val,int l,int r,int rt=1){
    if (l==r) {
        sum[rt]=val;
        return;
    }
    int m=(l+r)>>1;
    if (pos<=m)
        update(pos, val, lson);
    else
        update(pos, val, rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt=1){
    if (L<=l&&r<=R) {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int res=0;
    if (L<=m) {
        res=RMQ(res,query(L, R, lson));
    }
    if (R>m) {
        res=RMQ(res,query(L, R, rson));
    }
    return res;
}
int main(){
    int n,m,x,y;
    char s[2];
    while (scanf("%d%d",&n,&m)!=EOF) {
        build(1, n, 1);
        while (m--) {
            scanf("%s",s);
            scanf("%d%d",&x,&y);
            if (s[0]=='Q')
                printf("%d\n",query(x, y, 1, n, 1));
            else
                update(x, y, 1, n, 1);
        }
    }
}
