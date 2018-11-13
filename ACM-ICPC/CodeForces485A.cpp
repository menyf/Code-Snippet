// Wrote by MenYifan on 2015-05-26 08:27:21
// Exe.Time 62ms Exe.Memory 396K
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
int b[maxn]={};
int main(){
    int a,m,tmp;
    bool flag=false;
    cin>>a>>m;
    while (a<=10000000) {
        if (a%m==0) {
            printf("Yes");
            return 0;
        }
        a+=a%m;
    }
    puts("No");
    return 0;
}