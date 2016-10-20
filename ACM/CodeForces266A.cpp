// Wrote by MenYifan on 2016-03-09 19:39:55
// Exe.Time 30ms Exe.Memory 4K
//
//  20160309a.cpp
//  Cfiles
//
//  Created by ??? on 16/3/9.
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
#define maxn 100000+5
#define mod 1000000007
int main(){
    int n,ans=0;
    char s[100];
    scanf("%d",&n);
    scanf("%s",s);
    int pre=0;
    for (int i=1; i<n; i++) {
        if (s[i]==s[pre]) {
            ans++;
        }
        else{
            pre=i;
        }
    }
    cout<<ans<<endl;
}