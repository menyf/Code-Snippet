// Wrote by MenYifan on 2015-03-27 20:37:19
// Exe.Time 0ms Exe.Memory 272K
#include <stdio.h>
#include <iostream>
using namespace std;
double h,D,H;
double f(double x){
    return (h*D-H*x)/(D-x)+x;
}
double sf(double H,double h,double D){
    double r=D*h/H,l=0,mid,mmid;
    while (r-l>=1e-6) {
        mid=(l+r)/2;
        mmid=(mid+r)/2;
        if (f(mid)<f(mmid)) {
            l=mid;
        }
        else
            r=mmid;
    }
    return f(l);
}
int main(){
    int t;
    cin>>t;
    for (int j=0; j<t; j++) {
        scanf("%lf %lf %lf",&H,&h,&D);
        printf("%.3lf\n",sf(H,h,D));
    }
}