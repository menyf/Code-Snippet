// Wrote by MenYifan on 2016-08-23 15:50:19
// Exe.Time 2714ms Exe.Memory 1568K
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<iostream>
using namespace std;

long long  qmod(long long  a, long long  b, long long  m)
{
    long long  ans = 1LL;
    while(b != 0)
    {
        if(b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}


int main ()
{
   long long  c,k1,k2,b1;
   int cas=1;
    while(~scanf("%I64d%I64d%I64d%I64d",&c,&k1,&b1,&k2))
    {
        printf("Case #%d:\n",cas++);
        int flag=false;
        for (long long  i=1;i<c;i++)
        {
            long long a=i;
            long long b=c-qmod(i,k1+b1,c);
            if((qmod(i,b1+2*k1,c)+qmod(b,k2+1,c))%c==0)
            {
                //cout <<qmod(i,b1+2*k1,c)<<' '<<qmod(b,k2,c)<<endl;
                printf("%I64d %I64d\n",a,b);
                flag=true;
               // break;
            }

        }
        if(!flag)
        {
            printf("-1\n");
        }
    }
}
