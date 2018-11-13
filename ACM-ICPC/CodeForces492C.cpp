// Wrote by MenYifan on 2015-05-17 19:41:05
// Exe.Time 46ms Exe.Memory 792K

//
//  20150517c.cpp
//  Cfiles
//
//  Created by ??? on 15/5/17.
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
#define MAX 100005
#define inf 9999999
struct Node{
    int a,b;//a???????? b??????????essay??
} s[MAX];
int cmp(Node a,Node b){
    return a.b<b.b;
}
int main(){
    long long int n,r,i;
    long long int cnt=0,aim=0,sum=0;
    double ave;
    scanf("%lld %lld %lf",&n,&r,&ave);
    aim=ave*n;//?????
    for (i=0; i<n; i++) {
        scanf("%d%d",&s[i].a,&s[i].b);
        sum+=s[i].a;//total??????
    }
    sort(s, s+n, cmp);
    i=0;
    while (sum<aim&&i<n) {
        if (aim-sum>(r-s[i].a)) {
            sum+=(r-s[i].a);
            cnt+=(r-s[i].a)*s[i].b;
        }
        else{
            cnt+=(aim-sum)*s[i].b;
            break;
        }
        i++;
    }
    cout<<cnt<<endl;
}