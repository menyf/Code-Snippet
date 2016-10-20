// Wrote by MenYifan on 2015-04-15 22:30:51
// Exe.Time 46ms Exe.Memory 240K
//
//  20150415l.cpp
//  Cfiles
//
//  Created by ??? on 15/4/15.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100050
int main(){
    int n,m;
    string s1,s2;
    cin>>n>>m;
    map<string, string>s;
    for (int i=0; i<m; i++) {
        cin>>s1>>s2;
        if (s1.length()>s2.length()) {
            s[s1]=s2;
        }
    }
    for (int i=0; i<n; i++) {
        cin>>s1;
        if (s[s1]!="") {
            cout<<s[s1];
        }
        else
            cout<<s1;
        if (i!=n-1) {
            cout<<" ";
        }
    }
}