// Wrote by MenYifan on 2016-03-21 19:11:07
// Exe.Time 202ms Exe.Memory 41156K
//
//  RMQ.cpp
//  Cfiles
//
//  Created by ??? on 15/7/30.
//  Copyright (c) 2015? ???. All rights reserved.
//  hdu1754 I Hate It
//  RMQ:Range Minimum(Maximum) Query
//  ?????????????

#include <cstdio>
#include <algorithm>
#include "cmath"
using namespace std;
const int maxn = 150005;//???
const int NVB = 33;//?????????????2^32?????????33????
int mx[maxn][NVB],mn[maxn][NVB];
void init(int data[],int n){
    /*data???1??*/
    int k = log2(n);
    for(int i=1; i<=n; i++)
        mx[i][0] = mn[i][0] = data[i];
    for(int j=1; j<=k; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r,int flag){
    int k = log2(r-l+1);
    if(flag) return max(mx[l][k],mx[r-(1<<k)+1][k]);
    else return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int main(){
    int n,w;
    int a[maxn];
    scanf("%d%d",&n,&w);
    for (int i=1; i<=n; i++) {
        scanf("%d",a+i);
        a[i]++;
    }
    init(a, n);
    for (int i=1; i<=n; i++) {
        long long ans=-1;
        for (int j=1; j<=n; j+=i) {
            ans+=query(j, min(j+i-1,n), 1);
        }
        if (ans<=w) {
            printf("%d\n",i);
            return 0;
        }
    }
}