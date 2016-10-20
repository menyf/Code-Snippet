// Wrote by MenYifan on 2015-04-15 23:34:13
// Exe.Time 31ms Exe.Memory 116K
//
//  20150415j.cpp
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
    int n;
    cin>>n;
    string str1,str2,str3;
    map<string, string>s;
    int t=n;
    for (int i=0; i<n; i++) {
        cin>>str1>>str2;
        if (s.find(str1)==s.end()) {
            s[str1]=str1;
        }
        s[str2]=s[str1];
        s.erase(str1);
    }
    
    cout<<s.size()<<endl;
    map<string, string>::iterator it;
    for (it=s.begin(); it!=s.end(); it++) {
        cout<<(*it).second<<" "<<(*it).first<<endl;
    }
}