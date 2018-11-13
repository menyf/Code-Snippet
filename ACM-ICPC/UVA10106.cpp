// Wrote by MenYifan on 2015-07-20 17:57:38
// Exe.Time 4ms Exe.Memory 0K
//
//  20150720c.cpp
//  Cfiles
//
//  Created by ??? on 15/7/20.
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
#define maxn 1000000
void multi(char *a,char *b,char *c){
    
    int al=strlen(a);
    int bl=strlen(b);

    if (al==1&&a[0]=='0') {
        c[0]='0';
        c[1]='\0';
        return;
    }
    else if (bl==1&&b[0]=='0'){
        c[0]='0';
        c[1]='\0';
        return;
    }
    
    reverse(a,a+al);
    reverse(b,b+bl);
    for (int i=0; i<al; i++) {
        for (int j=0; j<bl; j++) {
            c[i+j]+=(a[i]-'0')*(b[j]-'0');
            if (c[i+j]>=10) {
                c[i+j+1]+=c[i+j]/10;
                c[i+j]%=10;
            }
        }
    }
    reverse(a,a+al);
    reverse(b,b+bl);
    for (int i=0; i<al+bl; i++) {
        c[i]+='0';
    }
    reverse(c,c+al+bl);
    if (c[0]=='0') {
        for (int i=0; i<al+bl-1; i++) {
            c[i]=c[i+1];
        }
        c[al+bl-1]='\0';
    }
}
int main(){
    char a[maxn],b[maxn],ans[maxn];
    while (scanf("%s%s",a,b)!=EOF) {
        multi(a,b,ans);
        printf("%s\n",ans);
        MemC(a);
        MemC(b);
        MemC(ans);
    }
}