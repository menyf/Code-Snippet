// Wrote by MenYifan on 2015-07-20 19:40:37
// Exe.Time 15ms Exe.Memory 1792K
//
//  20150720d.cpp
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
#define MAX 220
char s[1005][220];
void sum(char a[],char b[],char d[]){
    char c[MAX];
    int i,k=0,al=0,bl=0,cl=0;
    while(a[al])
        al++;
    al--;//al????a???
    while(b[bl])
        bl++;
    bl--;//bl????b???
    
    cl=al>bl?al:bl;//cl?max(al,bl)?1
    cl++;
    
    c[cl+1]='\0';
    while(cl>=0)
    {
        i=(al>=0?a[al]-'0':0) + (bl>=0?b[bl]-'0':0) + k;
        k=i/10;c[cl]='0'+i%10;
        al--;bl--;cl--;
    }
    
    int len=strlen(c);
    if (c[0]=='0') {
        for (int i=1; i<len; i++) {
            c[i-1]=c[i];
            if (i==len-1) {
                c[i]='\0';
            }
        }
    }
    strcpy(d, c);
}
int main(){
    s[0][0]='0';
    s[1][0]='1';
    for (int i=2; i<=1000; i++) {
        sum(s[i-1], s[i-2], s[i]);
    }
    int n,tmp=0;
    sf(n);
    while (n--) {
        sf(tmp);
        pf("%s\n",s[tmp]);
    }
}