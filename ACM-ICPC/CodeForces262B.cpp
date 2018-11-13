// Wrote by MenYifan on 2015-11-20 20:12:27
// Exe.Time 92ms Exe.Memory 396K
//
//  20151120a.cpp
//  Cfiles
//
//  Created by ??? on 15/11/20.
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
#define maxn 100005
bool cmp(int x,int y){
    return abs(x)>abs(y);
}
int main(){
    int a[maxn];
    int n,k,ans=0,last;
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n, cmp);
    for (int i=0; i<n; i++) {
        if (a[i]<0&&k>0) {
            a[i]*=-1;
            k--;
        }
        ans+=a[i];
    }
    if (k!=0&&k%2==1) {
        ans-=2*a[n-1];
    }
    cout<<ans<<endl;
}