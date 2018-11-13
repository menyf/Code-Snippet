// Wrote by MenYifan on 2015-10-21 20:50:04
// Exe.Time 146ms Exe.Memory 0K
//
//  20151018c.cpp
//  Cfiles
//
//  Created by ??? on 15/10/21.
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
#define debug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 100005<<1
int a[maxn],b[maxn];
int main(){
    int T,n,l,r,ans;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        ans=-1;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",a+i);
            a[i+n]=a[i];
        }
        for (int i=0; i<n; i++) {
            scanf("%d",b+i);
            b[i+n]=b[i];
        }
        for (int l=0; l<n; l=r) {
            int sum=0,num=0;
            r=l;
            while (ans==-1&&(num+=a[r]-b[r++])>=0) {
                if (++sum==n) {
                    ans=l;
                }
            }
            if (ans!=-1) {
                break;
            }
        }
        if (ans==-1) {
            printf("Case %d: Not possible\n",cas);
        }
        else
            printf("Case %d: Possible from station %d\n",cas,ans+1);
    }
}