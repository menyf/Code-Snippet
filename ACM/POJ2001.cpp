// Wrote by MenYifan on 2015-07-28 14:28:25
// Exe.Time 79ms Exe.Memory 2840K
//
//  20150727d.cpp
//  Cfiles
//
//  Created by ??? on 15/7/27.
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
//#define maxn 10005
#define maxn 20500
int ch[maxn][26];
int sz;
int val[maxn];
void init(){
    sz=1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
}
void insert(char *s){
    int u=0,i,c,len=strlen(s);
    for (i=0; i<len; i++) {
        c=s[i]-'a';
        if (!ch[u][c])
            ch[u][c]=sz++;
        u=ch[u][c];
        val[u]++;
    }
}
int query(char *s){
    int u=0,i,c,l=strlen(s);
    for (i=0; i<l; i++) {
        c=s[i]-'a';
        if (val[ch[u][c]]==1) {
            return i+1;
        }
        u=ch[u][c];
    }
    return l;
}
int main(){
    init();
    char s[1005][25];
    int i=0,ans;
    while (scanf("%s",s[i])!=EOF) {
        int len=strlen(s[i]);
        insert(s[i]);
        i++;
    }
    for (int j=0; j<i; j++) {
        ans=query(s[j]);
        printf("%s ",s[j]);
        for (int k=0; k<ans; k++) {
            printf("%c",s[j][k]);
        }
        printf("\n");
    }
}
