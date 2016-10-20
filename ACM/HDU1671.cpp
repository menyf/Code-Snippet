// Wrote by MenYifan on 2015-07-27 16:13:22
// Exe.Time 218ms Exe.Memory 13412K
//
//  20150727b.cpp
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
#define maxn 10005
int ch[11*maxn][26];
int sz;
int val[11*maxn];
struct node{
    char s[15];
    int len;
}trie[maxn];
void init(){
    sz=1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
}
void insert(char *s){
    int u=0,i,c,len=strlen(s);
    for (i=0; i<len; i++) {
        c=s[i]-'0';
        if (!ch[u][c])
            ch[u][c]=sz++;
        u=ch[u][c];
        val[u]++;
    }
}
int query(char *s){
    int u=0,i,c,l=strlen(s);
    for (i=0; i<l; i++) {
        c=s[i]-'0';
        if (!ch[u][c]) {
            return 0;
        }
        u=ch[u][c];
    }
    return val[u];
}
bool cmp(node a,node b){
    return a.len<b.len;
}
int main(){
    int t,n;
    sf(t);
    while (t--) {
        init();
        sf(n);
        for (int i=0; i<n; i++) {
            scanf("%s",trie[i].s);
            trie[i].len=strlen(trie[i].s);
            insert(trie[i].s);
        }
        sort(trie, trie+n, cmp);
        for (int i=0; i<n; i++) {
            if (query(trie[i].s)>1) {
                printf("NO\n");
                goto ll;
            }
        }
        printf("YES\n");
    ll:continue;
    }
}