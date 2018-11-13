// Wrote by MenYifan on 2016-03-09 20:16:21
// Exe.Time 30ms Exe.Memory 4K
//
//  20160309b.cpp
//  Cfiles
//
//  Created by ??? on 16/3/9.
//  Copyright   2016? ???. All rights reserved.
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
#define maxn 100000+5
#define mod 1000000007
char s[55];
int n,t,gcnt=0;
void work(){
    char tmp[55];
    strcpy(tmp, s);
    for (int i=0; i<n-1; i++) {
        if (tmp[i]=='B'&&tmp[i+1]=='G') {
            swap(s[i], s[i+1]);
        }
    }
}
int main(){
    cin>>n>>t;
    
    scanf("%s",s);

    for (int i=0; i<t; i++) {
        work();
    }
    
    for (int i=0; i<n; i++) {
        printf("%c",s[i]);
    }
    printf("\n");
}