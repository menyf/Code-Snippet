// Wrote by MenYifan on 2015-07-21 15:43:51
// Exe.Time 0ms Exe.Memory 1596K
//
//  20150720h.cpp
//  Cfiles
//
//  Created by ??? on 15/7/21.
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
int mod=9973;
struct matrix{
    int a[10][10];
    int n,m;
    matrix(int n=10,int m=10):n(n),m(m){
        init();
    }
    void init(){
        memset(a, 0, sizeof(a));
    }
    void unit(){
        for(int i=0;i<n;i++){
            a[i][i]=1;
        }
    }
    matrix operator *(const matrix &b){
        matrix ans(n,m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int k=0; k<n; k++) {
                    ans.a[i][j]+=(a[i][k]*b.a[k][j])%mod;
                    ans.a[i][j]%=mod;
                }
            }
        }
        return ans;
    }
};
matrix qpow(matrix a,int k){
    matrix ans(a.n,a.n);
    ans.unit();
    
    while (k) {
        if (k&1) {
            ans=ans*a;
        }
        k>>=1;
        a=a*a;
    }
    return ans;
}
int main(){
    int n,l,t,ans;
    sf(n);
//    bug;
    while (n--) {
        ans=0;
        sff(l,t);
        matrix a(l,l);
        for (int i=0; i<l; i++) {
            for (int j=0; j<l; j++) {
                sf(a.a[i][j]);
            }
        }
        a=qpow(a, t);
//        
//            for (int i=0; i<a.n; i++) {
//                for (int j=0; j<a.n; j++) {
//                    pf("%d ",a.a[i][j]);
//                }
//                pf("\n");
//            }
//        
        for (int i=0; i<l; i++) {
            ans+=a.a[i][i];
        }
        cout<<ans%mod<<endl;
    }
}