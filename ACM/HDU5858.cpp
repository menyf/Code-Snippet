#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
double hailun (double a,double b,double c)
{
    double p=(a+b+c)/2;

    double S=sqrt(p*(p-a)*(p-b)*(p-c));
    return S;
}

double jiao (double c,double b,double a)
{
    double temp=(c*c-b*b-a*a)/2/a/b;
    return acos(-temp);
}
int main ()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double l;
        scanf("%lf",&l);
        double temp=jiao(l,l/2,l/sqrt(2));

        double temp2=2*acos(-1)-2*temp;
        temp=2*jiao(l/2,l,l/sqrt(2));
        double s1=temp/2*l*l-2*hailun(l,l/2,l/sqrt(2));
        double s2=temp2/2*(l/2)*(l/2);
        printf("%.2f\n",2*s2-2*s1);



    }
}
