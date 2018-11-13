// Wrote by MenYifan on 2015-07-21 14:02:59
// Exe.Time 530ms Exe.Memory 206040K
//
//  20150720g.cpp
//  Cfiles
//
//  Created by ??? on 15/7/21.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 10005
int mp[maxn][maxn]={};
int a[maxn][2];
int t[maxn]={};//????????????/4???
int multi(int *a,int *b,int na,int nb,int *ans){
    for (int i=0; i<na; i++) {
        for (int j=0; j<nb; j++) {
            ans[i+j]+=a[i]*b[j];
            if (ans[i+j]>=10000) {
                ans[i+j+1]+=ans[i+j]/10000;
                ans[i+j]=ans[i+j]%10000;
            }
        }
    }
    if (ans[na+nb-1]==0) {
        return na+nb-1;
    }
    else{
        return na+nb;
    }
}
void get(){
    mp[0][0]=1;t[0]=1;
    mp[1][0]=1;t[1]=1;
    for (int i=2; i<10000; i++) {
        t[i]=multi(mp[i-1],a[i],t[i-1],1,mp[i]);
    }
    t[10000]=multi(mp[9999],a[10000],t[9999],2,mp[10000]);
}
void print(int n){
    printf("%d",mp[n][t[n]-1]);
    for (int j=t[n]-2; j>=0; j--) {
        printf("%04d",mp[n][j]);
    }
    printf("\n");
}
int main(){
    for (int i=1; i<=9999; i++) {
        a[i][0]=i;
    }
    a[10000][0]=0;
    a[10000][1]=1;
    get();
    int n;
    
    while (sf(n)!=EOF) {
        print(n);
    }
}
