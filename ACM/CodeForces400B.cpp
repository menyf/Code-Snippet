// Wrote by MenYifan on 2015-07-30 17:10:00
// Exe.Time 31ms Exe.Memory 36K
//
//  20150730b.cpp
//  Cfiles
//
//  Created by ??? on 15/7/30.
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
#define maxn 1005
int main(){
    char s[maxn];
    bool flag=true;
    set<int> st;
    int n,m,pos0,pos1;
    sff(n, m);
    for (int i=0; i<n; i++) {
        scanf("%s",s);
        pos0=INF;
        pos1=0;
        for (int i=0; i<m; i++) {
            if (s[i]=='G') {
                pos0=i;
            }
            if (s[i]=='S') {
                pos1=i;
            }
        }
        if (pos1-pos0>0) {
            st.insert(pos1-pos0);
        }
        else
            flag=false;
    }
    if (!flag) {
        printf("-1\n");
    }
    else{
        cout<<st.size()<<endl;
    }
        
}