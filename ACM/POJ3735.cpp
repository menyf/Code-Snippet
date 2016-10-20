// Wrote by MenYifan on 2015-07-22 14:31:11
// Exe.Time 188ms Exe.Memory 1568K
//
//  20150720i.cpp
//  Cfiles
//
//  Created by ??? on 15/7/22.
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
#define maxn 10005
int n;
struct matrix{
    ll a[105][105];
}sq,ans;
matrix multi(matrix x,matrix y,int m,int n,int p){
    matrix ans;
    memset(ans.a, 0, sizeof(ans.a));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (x.a[i][j]==0) {
                continue;
            }
            for (int k=0; k<p; k++) {
                ans.a[i][k]+=x.a[i][j]*y.a[j][k];
            }
        }
    }
    return ans;
}
matrix qpow(matrix x,int t){
    matrix ans;
    
    memset(ans.a, 0, sizeof(ans.a));
    for (int i=0; i<=n; i++)
        ans.a[i][i]=1;
    
    while (t) {
        if (t&1) {
            ans=multi(x, ans, n+1, n+1, n+1);
        }
        t>>=1;
        x=multi(x, x, n+1, n+1, n+1);
    }
    return ans;
}
int main(){
    int tmp1,tmp2,m,k;
    char s[2];
    while (sfff(n, m, k),n+m+k) {
        
        //????????
        memset(ans.a, 0, sizeof(ans.a));
        ans.a[n][0]=1;
        
        //??????
        memset(sq.a, 0, sizeof(sq.a));
        for (int i=0; i<=n; i++) {
            sq.a[i][i]=1;
        }
        
        for (int i=0; i<k; i++) {
            scanf("%s",s);
            if (s[0]=='g') {
                //???
                sf(tmp1);
                sq.a[tmp1-1][n]++;
            }
            else if (s[0]=='e'){
                //???
                sf(tmp1);
                for (int i=0; i<=n; i++)
                    sq.a[tmp1-1][i]=0;
            }
            else if (s[0]=='s'){
                sff(tmp1, tmp2);
                for (int i=0; i<=n; i++){
                    swap(sq.a[tmp1-1][i], sq.a[tmp2-1][i]);
                }
            }
        }
        
            //??m?
        sq=qpow(sq, m);
            
        ans=multi(sq, ans,n+1,n+1,1);
            
        for (int i=0; i<n; i++){
            pf("%lld",ans.a[i][0]);
            if (i!=n-1) {
                printf(" ");
            }
            else{
                puts("");
            }
        }
    }
}
