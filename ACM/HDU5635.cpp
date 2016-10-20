//
//  bc74a.cpp
//  Cfiles
//
//  Created by 门一凡 on 16/3/5.
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
#define maxn 100005
#define mod 1000000007
int a[maxn];
int main(){
    int t;
    cin>>t;
    while (t--) {
        Memset(a, 0);
        int n;
        ll ans=26;
        cin>>n;
        bool flag=true;
        for (int i=1; i<=n-1; i++) {
            cin>>a[i];
            if (a[i]==0) {
                ans=ans*25%mod;
            }
            
            if (a[i-1]!=0&&a[i-1]-1!=a[i]) {
                flag=false;
            }
        }
        
        if (flag&&(a[n-1]==0||a[n-1]==1)) {
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}
