// Wrote by MenYifan on 2015-03-13 16:01:11
// Exe.Time 15ms Exe.Memory 1580K

#include <stdio.h>
#include<iostream>
using namespace std;
int t=0;
void func(int n){
    t++;
    if (n==1) {
        return;
    }
    if (n%2==1) {
        n=3*n+1;
        func(n);
    }
    else{
        n=n/2;
        func(n);
    }
}
int main(){
    int i,j;
    while (scanf("%d%d",&i,&j)!=EOF) {
        int max=0;
        int m=i;
        while (m!=j) {
            t=0;
            func(m);
            if (t>max) {
                max=t;
            }
            if (i<j) {
                m++;
            }
            else if(i>j)
                m--;
        }
        t=0;
        func(m);
        if (t>max) {
            max=t;
        }
        printf("%d %d %d\n",i,j,max);
    }
}