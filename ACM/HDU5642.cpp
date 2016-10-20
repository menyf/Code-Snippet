//
//  bc75c.cpp
//  Cfiles
//
//  Created by 门一凡 on 16/3/12.
//  Copyright &#169; 2016年 门一凡. All rights reserved.
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
#define maxn 100000+5
#define mod 1000000007
ll dp[2005][4];
ll ans[2005]={1};
int main(){
    for (int i=1; i<=2000; i++) {
        //第i位与i-1位不同，共有dp[i][0]种方法
        dp[i][0]=25*ans[i-1]%mod;
        if (i==1)
            dp[i][0]++;
        ans[i]+=dp[i][0];
        
        //j=1时: 第i位与第i-1位相同
        //j=2时: 第j位与第i-1,i-2位相同
        for (int j=1; j<3; j++) {
            dp[i][j]=dp[i-1][j-1];
            ans[i]+=dp[i][j];
            ans[i]%=mod;
        }
    }
    
    int t;
    cin>>t;
    while (t--) {
        int k;
        cin>>k;
        cout<<ans[k]<<endl;
    }
}
