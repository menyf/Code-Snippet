// Wrote by MenYifan on 2015-11-22 23:49:46
// Exe.Time 0ms Exe.Memory 0K
//
//  20151122c.cpp
//  Cfiles
//
//  Created by ??? on 15/11/22.
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
    char s[105];
    while (scanf("%s",s)!=EOF) {
        int len=strlen(s);
        int zero=0,cnt1=0,cnt2=0;//cnt1 ?? ?0 0?????
                                 //cnt2 ?? ?0 X?????
                                 //zero ?? "0"???
        
        if (s[0]=='0'&&s[len-1]=='0') {
            cnt1++;
        }
        for (int i=0; i<len; i++) {
            if (s[i]=='0')
                zero++;
            if (i>0&&s[i]=='0'&&s[i-1]=='0')
                cnt1++;
        }
        
        cnt2=zero;
        
        if (zero*cnt2>cnt1*len) {
            cout<<"ROTATE"<<endl;
        }
        else if (zero*zero==cnt1*len)
            cout<<"EQUAL"<<endl;
        else
            cout<<"SHOOT"<<endl;
        
    }
}