// Wrote by MenYifan on 2015-10-25 18:40:36
// Exe.Time 3ms Exe.Memory 0K
//
//  20151025b.cpp
//  Cfiles
//
//  Created by ??? on 15/10/25.
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
#define maxn 10005
int main(){
    char str1[105],str2[105];
    while (scanf("%s %s",str1,str2)!=EOF) {
        int cnt1[26]={},cnt2[26]={},ans=0;
        for (int i=0; str1[i]; i++) {
            cnt1[str1[i]-'A']++;
        }
        for (int i=0; str2[i]; i++) {
            cnt2[str2[i]-'A']++;
        }
        
        sort(cnt1, cnt1+26);
        sort(cnt2, cnt2+26);
        
        for (int i=0; i<26; i++) {
            if (cnt1[i]==cnt2[i]) {
                ans++;
            }
        }
        
        if (ans==26) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}