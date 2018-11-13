// Wrote by MenYifan on 2015-10-16 20:01:25
// Exe.Time 92ms Exe.Memory 1352K
//
//  20151016b.cpp
//  Cfiles
//
//  Created by ??? on 15/10/16.
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
#define maxn 100005
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,c[maxn]={},a[maxn]={},b[maxn]={},ans=99999;
    sf(n);
    for (int i=0; i<n; i++) {
        sf(c[i]);
    }
    sort(c, c+n);
    
    int index=0;
    a[0]=c[0];
    b[0]++;
    for (int i=1; i<n; i++) {
        if (c[i]==c[i-1]) {
            b[index]++;
        }
        else{
            index++;
            a[index]=c[i];
            b[index]++;
        }
    }
    n=index;
    
//    for (int i=0; i<=n; i++) {
//        cout<<i<<" "<<a[i]<<":"<<b[i]<<endl;
//    }
//    bug;
    
    int pre=0;
    
    for (int i=0; i<=n; i++) {
        int pos=lower_bound(a, a+n+1, 2*a[i])-a;
//        cout<<a[i]<<" "<<pos<<endl;
        if (pos==n+1){
            ans=min(ans, pre);
            break;
        }

        if (a[pos]==2*a[i]) pos++;
    
        if (pos==n+1){
            ans=min(ans, pre);
            break;
        }
        
        int tmp=0;
        for (int j=pos; j<=n; j++) {
            tmp+=b[j];
        }
        ans=min(ans, pre+tmp);
        
        pre+=b[i];
    }
    cout<<ans<<endl;
}
//6 1 100 101 102 103 4500