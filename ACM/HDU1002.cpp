// Wrote by MenYifan on 2015-07-20 15:32:54
// Exe.Time 15ms Exe.Memory 1576K
//
//  20150720a.cpp
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
#define maxn 10005
void sum(char *a,char *b,char *ans){
    int al=strlen(a);
    bool flag=false;
    int bl=strlen(b);
    int len=max(al, bl);
    reverse(a, a+al);
    reverse(b, b+bl);
    for (int i=0; i<len; i++) {
        if (a[i]=='\0')
            a[i]+='0';
        else if (b[i]=='\0')
            b[i]+='0';
        ans[i]+=a[i]+b[i]-2*'0';
        if (ans[i]>=10) {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
            if (i==len-1) {
                flag=true;
            }
        }
        ans[i]+='0';
    }
    ans[len]+='0';
    a[al]='\0';
    reverse(a, a+al);
    reverse(b, b+bl);
    b[bl]='\0';
    reverse(ans, ans+len+1);
}
int main(){
    int t;
    sf(t);
    char a[1005],b[1005],ans[1005];
    For(i, t){
        MemC(a);
        MemC(b);
        MemC(ans);
        scanf("%s%s",a,b);
        sum(a, b, ans);
        if (ans[0]=='0') {
            pf("Case %d:\n%s + %s = %s\n",i,a,b,ans+1);
        }
        else{
            pf("Case %d:\n%s + %s = %s\n",i,a,b,ans);
        }
        if (i!=t) {
            cout<<endl;
        }
        
    }
}