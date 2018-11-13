// Wrote by MenYifan on 2015-05-24 18:33:24
// Exe.Time 31ms Exe.Memory 8K
//
//  20150524a.cpp
//  Cfiles
//
//  Created by ??? on 15/5/24.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#define maxn 100050
#define inf 999999
#define PI acos(-1.0)
#define debug puts("-------------------");
using namespace std;
int main(){
    int n,m,cntx=0,cnty=0,cnt=0,i,j;
    int b[100],g[100];
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",b+i);
    }
    cin>>m;
    for (int i=0; i<m; i++) {
        scanf("%d",g+i);
    }
    sort(b, b+n);
    sort(g, g+m);
    while (cntx<n&&cnty<m) {
        if (b[cntx]-g[cnty]<=1&&g[cnty]-b[cntx]<=1) {
            cnt++;
            cntx++;
            cnty++;
        }
        else if (b[cntx]-g[cnty]>1){
            cnty++;
        }
        else if (g[cnty]-b[cntx]>1){
            cntx++;
        }
    }
    cout<<cnt<<endl;
}