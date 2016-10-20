// Wrote by MenYifan on 2015-10-07 21:10:43
// Exe.Time 9ms Exe.Memory 0K
//
//  20151007a.cpp
//  Cfiles
//
//  Created by ??? on 15/10/7.
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
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define vset(a,val) memset(a,val,sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 20005
int d[maxn];
int h[maxn];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    int n,m;
    while (sff(n, m),n&&m) {
        vset(d, 0);
        vset(h, 0);
        bool flag=true;
        int ans=0;
        for (int i=0; i<n; i++) {
            sf(d[i]);
        }
        for (int i=0; i<m; i++) {
            sf(h[i]);
        }
        sort(d, d+n, cmp);
        sort(h, h+m, cmp);
        int index=0;
        for (int i=0; i<n; i++) {
            if (index==m) {
                flag=false;
                break;
            }
            while (h[index]<d[i]) {
                index++;
                if (index==m) {
                    flag=false;
                    break;
                }
            }
            if (index==m) {
                flag=false;
                break;
            }
            ans+=h[index++];
        }
        if (flag) {
            cout<<ans<<endl;
        }
        else
            cout<<"Loowater is doomed!"<<endl;
    }
}