#include <iostream>
#include <stdio.h>
using namespace std;
int dp(int a[],int n){
    int vis[1050]={1},mx=0;
    if (n==1) {
        mx=1;
    }
    for (int i=1; i<n; i++) {
        vis[i]=1;
        for (int j=0; j<i; j++) {
            if (a[j]<a[i]&&vis[i]<vis[j]+1) {
                vis[i]=vis[j]+1;
            }
        }
        if (mx<vis[i]) {
            mx=vis[i];
        }
    }
    return mx;
}
int main(){
    int a[1050]={};
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",a+i);
    }
    printf("%d",dp(a,n));
}
