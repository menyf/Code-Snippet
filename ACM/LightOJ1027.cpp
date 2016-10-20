// Wrote by MenYifan on 2016-09-04 15:58:13
// Exe.Time 0ms Exe.Memory 1688K
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
int main ()
{
    int T;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,x;
        scanf("%d",&n);
        int  sum=0,num=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x>=0)
            {
                num++;
            }
            sum+=abs(x);
        }
        if(num==0)
        {
            printf("Case %d: inf\n",cas++);
        }
        else
        {
            int g=__gcd(sum,num);
            printf("Case %d: %d/%d\n",cas++,sum/g,num/g);
        }
    }
    return 0;
}