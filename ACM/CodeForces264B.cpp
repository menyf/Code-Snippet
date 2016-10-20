// Wrote by MenYifan on 2016-03-03 08:54:22
// Exe.Time 654ms Exe.Memory 9564K
//
//  20160302b.cpp
//  Cfiles
//
//  Created by ??? on 16/3/2.
//  Copyright   2016? ???. All rights reserved.
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
#define maxn 100005
int a[maxn];
int dp[maxn];
vector<int>t[maxn];
int main(){
    int n,ans=0,tmp;
    for (int i=2; i<maxn; i++) {
        for (int j=i; j<maxn; j+=i) {
            t[j].push_back(i);
        }
    }
    while (cin>>n) {
        ans=1;
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) {
            cin>>tmp;
            int mx=1;
            for (vector<int>::iterator it=t[tmp].begin(); it!=t[tmp].end(); it++) {
                mx=max(mx, dp[*it]+1);
            }
            for (vector<int>::iterator it=t[tmp].begin(); it!=t[tmp].end(); it++) {
                dp[*it]=max(dp[*it], mx);
            }
        }
        for (int i=0; i<maxn; i++) {
            ans=max(ans, dp[i]);
        }
        cout<<ans<<endl;
    }
//    for (int i=2; i<maxn; i++) {
//        for (int j=i; j<maxn; j+=i) {
//            t[j].push_back(i);
//        }
//    }
//    int n,tmp;
//    scanf("%d",&n);
//    for (int i=0; i<n; i++) {
//        scanf("%d",&tmp);
//        int tp=1;
//        for (vector<int>::iterator it=t[tmp].begin(); it!=t[tmp].end(); it++) {
//            tp=max(tp, dp[*it]+1);
//        }
//        for (vector<int>::iterator it=t[tmp].begin(); it!=t[tmp].end(); it++) {
//            dp[*it]=max(dp[*it], tp);
//        }
//    }
//    int ans=1;
//    for (int i=0; i<maxn; i++) {
//        ans=max(ans, dp[i]);
//    }
//    printf("%d\n",ans);
}