// Wrote by MenYifan on 2015-11-23 14:57:59
// Exe.Time 3ms Exe.Memory 0K
//
//  20151122d.cpp
//  Cfiles
//
//  Created by ??? on 15/11/23.
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
#define maxn 1005
#define mod 10056
int dp[maxn][maxn];//dp[i][j]??i???j?????????
int main(){
    dp[1][1]=1;
    dp[2][1]=1;
    dp[2][2]=2;
    for (int i=3; i<=1003; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j]=j*(dp[i-1][j]+dp[i-1][j-1]);
            dp[i][j]=(mod+dp[i][j]%mod)%mod;
        }
    }
    int t,x,ans;
    cin>>t;
    for (int cas=1; cas<=t; cas++) {
        cin>>x;
        ans=0;
        for (int i=1; i<=x; i++) {
            ans+=dp[x][i];
        }
        cout<<"Case "<<cas<<": "<<ans%mod<<endl;
    }
}