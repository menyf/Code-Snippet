// Wrote by MenYifan on 2015-12-13 18:23:03
// Exe.Time 15ms Exe.Memory 1568K
//
//  20151213b.cpp
//  Cfiles
//
//  Created by ??? on 15/12/13.
//  Copyright   2015? ???. All rights reserved.
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
#define maxn 10005
inline void scan(int &x)
{
    char c; for(c = getchar();c < '0' || c > '9';c = getchar());    x = c - '0';
    for(c = getchar();c >= '0' && c <= '9';c = getchar())   x = (x << 1) + (x << 3) + c - '0';
}
char s[100000];
int main(){
    while (scanf("%s",s),s[0]!='#') {
        int len=strlen(s);
        int cnt=0;
        for (int i=0; i<len-1; i++) {
            if (s[i]=='1') {
                cnt++;
            }
            printf("%c",s[i]);
        }
        if (s[len-1]=='o') {
            if (cnt%2==1) {
                printf("0\n");
            }
            else
                printf("1\n");
        }
        else{
            if (cnt%2==0) {
                printf("0\n");
            }
            else
                printf("1\n");
        }
    }
}