// Wrote by MenYifan on 2015-08-18 23:44:29
// Exe.Time 280ms Exe.Memory 56404K
//
//  20150727e.cpp
//  Cfiles
//
//  Created by ??? on 15/7/28.
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
#define maxn 500005
struct Trie{
    int id,val;
    int next[26];
    Trie(){
        memset(next, 0, sizeof(next));
        id=val=0;
    }
}ch[maxn];
int sz=0;
void insert(char *s,int pos){
    int u=0;
    for (int i=0; s[i]; i++) {
        int v=s[i]-'a';
        if (!ch[u].next[v]) ch[u].next[v]=++sz;
        u=ch[u].next[v];
        if (ch[u].id!=pos) ch[u].val++;
        ch[u].id=pos;
    }
}
int query(char *s){
    int u=0;
    for (int i=0; s[i]; i++) {
        int v=s[i]-'a';
        if (!ch[u].next[v]) return 0;
        u=ch[u].next[v];
    }
    return ch[u].val;
}
int main(){
    int p,q;
    char str[25];
    cin>>p;
    while (p--) {
        scanf("%s",str);
        int len=strlen(str);
        for (int j=0; j<len; j++)
            insert(str+j, p+1);
    }
    cin>>q;
    while (q--) {
        scanf("%s",str);
        cout<<query(str)<<endl;
    }
    return 0;
}
