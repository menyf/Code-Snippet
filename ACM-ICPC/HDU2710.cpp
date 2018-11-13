// Wrote by MenYifan on 2015-12-13 18:15:01
// Exe.Time 0ms Exe.Memory 1652K
//
//  20151213a.cpp
//  Cfiles
//
//  Created by ??? on 15/12/13.
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
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int prime[maxn]={1,2},num[maxn*2]={};
void make_form(){
    int pcnt=0;
    for (int i=2; i<=20000; i++) {
        if (num[i]==0) {
            prime[pcnt++]=i;
            for (int j=i; j<=20000; j+=i) {
                num[j]=i;
            }
        }
    }
}
int main(){
    make_form();
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=1,x;
        while (n--) {
            scanf("%d",&x);
            if (num[x]>num[ans]) {
                ans=x;
            }
        }
        printf("%d\n",ans);
    }
}