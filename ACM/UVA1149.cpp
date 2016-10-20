// Wrote by MenYifan on 2015-11-15 19:42:55
// Exe.Time 19ms Exe.Memory 0K
//
//  20151115b.cpp
//  Cfiles
//
//  Created by ??? on 15/11/15.
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
#define maxn 100050
int a[maxn];
int main(){
    int t,n,len;
    bool flag=false;
    scanf("%d",&t);
    while (t--) {
        if (flag) {
            cout<<endl;
        }
        int cnt=0,ans=0;
        scanf("%d%d",&n,&len);
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        sort(a, a+n);
        
        int f=0,b=n-1;
        while (f<=b) {
            if (f==b) {
                ans+=1;
                break;
            }
            else{
                if (a[f]+a[b]<=len) {
                    f++;
                    b--;
                    ans++;
                }
                else{
                    ans++;
                    b--;
                }
            }
            
        }
        cout<<ans<<endl;
        flag=true;
    }
}