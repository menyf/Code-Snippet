// Wrote by MenYifan on 2015-07-09 19:49:24
// Exe.Time 30ms Exe.Memory 12K
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int i,sum=0,n,m;
    int tv[150]={};
    cin>>n>>m;
    for (i=0; i<n; i++)
        cin>>tv[i];
    sort(tv, tv+n);
    for (i=0; tv[i]<0&&i<m; i++) {
        sum+=-tv[i];
    }
    printf("%d",sum);
}
