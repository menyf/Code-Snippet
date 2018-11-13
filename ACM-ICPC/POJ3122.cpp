// Wrote by MenYifan on 2015-03-27 22:45:21
// Exe.Time 47ms Exe.Memory 780K
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define pai acos(-1.0)
using namespace std;
int main()
{
    int t;
    int n,f;
    double a_,a[10000];
    scanf("%d",&t);
    while (t--)
    {
        double sum=0.0;
        scanf("%d %d",&n,&f);
        f++;
        for (int i=0; i<n; i++)
        {
            scanf("%lf",&a_);
            a[i]=pai*a_*a_;
            sum+=a[i];
        }
        double left=0.0,right=sum/f,mid;
        while (right-left>1e-5)
        {
            mid=(left+right)/2;
            int tmp=0;
            for (int i=0;i<n;i++)
                tmp+=int (a[i]/mid);
            if (tmp<f)
                right=mid;
            else
                left=mid;
        }
        printf("%.4f\n",mid);
    }
}