// Wrote by MenYifan on 2015-11-07 19:29:09
// Exe.Time 30ms Exe.Memory 104K
//
//  20151107b.cpp
//  Cfiles
//
//  Created by ??? on 15/11/7.
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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100005+1;
char s[maxn];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    int flag=-1;
    for (int i=0; i<len; i++) {
        if (flag==-1&&i==len-1) {
            break;
        }
        if (flag==-1&&s[i]=='0') {
            flag=1;
            continue;
        }
        printf("%c",s[i]);
//        if (s[i]=='1'&&flag==-1) {
//            flag=0;
//        }
    }
    printf("\n");
}