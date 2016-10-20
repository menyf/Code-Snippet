// Wrote by MenYifan on 2015-07-09 18:55:15
// Exe.Time 62ms Exe.Memory 40K
//
//  20150709g.cpp
//  Cfiles
//
//  Created by ??? on 15/7/9.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int main(){
    int a[1050]={},mx=0;
    set<int>s;
    int n,tmp;
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",&tmp);
        s.insert(tmp);
        a[tmp]++;
        if (a[tmp]>mx) {
            mx=a[tmp];
        }
    }
    cout<<mx<<" "<<s.size()<<endl;
}