//
//  64a.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/11/29.
//  Copyright &#169; 2015年 门一凡. All rights reserved.
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
#define maxn 10005
int main(){
    char s[50];
    while (scanf("%s",s)!=EOF) {
        int len=strlen(s);
        int sum=0;
        for (int i=0; i<len; i++) {
            sum+=s[i]-'0';
        }
        int tail=s[len-1]-'0';
        if (tail%2==0||tail%5==0||sum%3==0) {
            puts("YES");
        }
        else
            puts("NO");
    }
}
