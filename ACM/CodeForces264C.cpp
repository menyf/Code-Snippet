// Wrote by MenYifan on 2016-03-06 10:45:37
// Exe.Time 2900ms Exe.Memory 2360K
//
//  20160302c.cpp
//  Cfiles
//
//  Created by ??? on 16/3/5.
//  Copyright   2016? ???. All rights reserved.
//

//????
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
#define INF 1e18
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 100005
ll c[100005],v[100005];
ll dp[100005];
int main(){
    int n,q;
    ll v1,v2,v3,v4;
    cin>>n>>q;
    for (int i=1; i<=n; i++) {
        cin>>v[i];
    }
    for (int i=1; i<=n; i++) {
        cin>>c[i];
    }
    int a,b;
    while (q--) {
        cin>>a>>b;
        ll mx=-INF,mmx=-INF,ans=0;
        int pos=0,ppos=0;
        for (int i=0; i<maxn; i++) {
            dp[i]=-INF;
        }
        
        for (int i=1; i<=n; i++) {
            v1=v[i]*b;
            v2=dp[c[i]]+a*v[i];
            v4=dp[c[i]];
            if (c[i]==c[pos]) {
                v3=mmx+v[i]*b;
            }
            else{
                v3=mx+v[i]*b;
            }
            
            dp[c[i]]=max(max(v1, v2), max(v3, v4));
            
            if (dp[c[i]]>mx) {
                if (c[i]==c[pos]) {
                    pos=i;
                    mx=dp[c[i]];
                }
                else{
                    ppos=pos;
                    mmx=mx;
                    pos=i;
                    mx=dp[c[i]];
                }
                ans=max(ans, mx);
            }
            else if (dp[c[i]]>mmx){
                if (c[i]!=c[pos]) {
                    ppos=i;
                    mmx=dp[c[i]];
                }
            }
            
        }
        cout<<ans<<endl;
    }
}