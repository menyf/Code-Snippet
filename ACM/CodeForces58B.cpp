// Wrote by MenYifan on 2015-07-14 20:38:03
// Exe.Time 60ms Exe.Memory 8K
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int n,j=0,a[1000]={};
    cin>>n;
    a[0]=n;
    while (n!=1) {
        for (int i=2; i<=n; i++) {
            if (n%i==0) {
                n/=i;
                a[++j]=n;
                break;
            }
        }
    }
    for (int i=0; i<=j; i++) {
        printf("%d ",a[i]);
    }
}
