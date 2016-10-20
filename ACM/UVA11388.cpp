// Wrote by MenYifan on 2015-03-20 21:56:19
// Exe.Time 19ms Exe.Memory 0K
#include <stdio.h>
#include <iostream>
using namespace::std;
int main(){
    int t,a,b;
    cin>>t;
    for (int i=0; i<t; i++) {
        cin>>a>>b;
        if (b%a==0) {
            printf("%d %d\n",a,b);
        }
        else
            printf("-1\n");
    }
}