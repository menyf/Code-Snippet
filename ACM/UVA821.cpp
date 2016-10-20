// Wrote by MenYifan on 2015-11-09 22:57:18
// Exe.Time 66ms Exe.Memory 0K
//
//  20151108d.cpp
//  Cfiles
//
//  Created by ??? on 15/11/9.
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
#define INF 0x3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int mp[105][105];
int u,v,cas=1;
int main(){
    while (scanf("%d%d",&u,&v),u+v) {
        
        for (int i=1; i<105; i++) {
            for (int j=1; j<105; j++) {
                mp[i][j]=9999;
            }
        }
        
        mp[u][v]=1;
        int sum=0;
        int t=0;
        int n=max(u, v);
        
        while (scanf("%d%d",&u,&v),u+v) {
            mp[u][v]=1;
            n=max(n, max(u, v));
        }
        for (int k=1; k<=n; k++) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (mp[i][j]>mp[i][k]+mp[k][j]) {
                        mp[i][j]=mp[i][k]+mp[k][j];
                    }
                }
            }
        }
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
//                cout<<mp[i][j]<<" ";
                if (i!=j&&mp[i][j]!=9999) {
                    sum+=mp[i][j];
                    t++;
                }
            }
        }
        
//        cout<<sum<<" "<<t<<endl;
        
        printf("Case %d: average length between pages = %.3f clicks\n",cas++,1.0*sum/t);
        
        
    }
    
}

/*
 1 2 2 4 1 3 3 1 4 3 0 0
 1 2 1 4 4 2 2 7 7 1 0 0
 
 
 for (int k=1; k<=n; k++) {
 for (int i=1; i<=n; i++) {
 for (int j=1; j<=n; j++) {
 if (mp[i][j]>mp[i][k]+mp[k][j]) {
 mp[i][j]=mp[i][k]+mp[k][j];
 }
 }
 }
 }
 
 


*/