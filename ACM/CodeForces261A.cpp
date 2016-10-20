// Wrote by MenYifan on 2015-11-20 20:32:43
// Exe.Time 686ms Exe.Memory 392K
//
//  20151120b.cpp
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
    return x>y;
}
int main(){
    int ans=0,index=0;
    int q[maxn]={};
    int m,n,mn=999999,tmp;
    cin>>m;
    for (int i=0; i<m; i++){
        cin>>tmp;
        mn=min(mn, tmp);
    }
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>q[i];
    sort(q, q+n, cmp);
    while (index<n) {
        for (int i=0; i<mn&&i+index<n; i++) {
            ans+=q[i+index];
        }
        index+=2+mn;
    }
    cout<<ans<<endl;
}