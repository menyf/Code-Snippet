// Wrote by MenYifan on 2016-03-02 19:45:37
// Exe.Time 265ms Exe.Memory 4908K
//
//  20160302a.cpp
//  Cfiles
//
//  Created by ??? on 16/3/2.
//  Copyright   2016? ???. All rights reserved.
//  Escape from Stones

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
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 1000500
char s[maxn];
int ans[maxn];
int main(){
//    scanf("%s",s);
    int l=0,r,len;
    while (scanf("%s",s)!=EOF) {
        l=0;
        len=strlen(s);
        r=len-1;
        for (int i=0; i<len; i++) {
            if (s[i]=='l') {
                ans[r--]=i+1;
            }
            else
                ans[l++]=i+1;
        }
        
        for (int i=0; i<len; i++) {
            printf("%d\n",ans[i]);
        }
    }
    
}