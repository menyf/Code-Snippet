// Wrote by MenYifan on 2016-08-13 22:15:43
// Exe.Time 0ms Exe.Memory 1632K
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
const long long mod= 1000000007;
long long dp[60][60];
long long c[60][60];
long long  qmod(long long  a,long long  b)
{
    long long  ans=1LL;
    while(b!=0)
    {
        if(b&1)
        {ans=(ans*a)%mod;}
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

void f1()
{
    c[0][0]=1;
    for (int i=1;i<=50;i++)
    {
        c[i][0]=1;
        for (int j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
            //cout <<c[i][j]<<endl;
        }
    }
}

void f2()
{
    f1();
    dp[1][1]=1;
    for (int i=1;i<=50;i++)
    {
        for (int j=1;j<=50;j++)
        {
            if(i==1||j==1)
            {
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=dp[i][j-1]*(qmod(2,i)-1)%mod;
            for (int k=1;k<i;k++)
            {
                long long temp=dp[i-k][j-1]*c[i][k]%mod*qmod(2,i-k)%mod;
                dp[i][j]=(dp[i][j]+temp)%mod;
            }
        }
    }
}
int main ()
{
    int x,y;
    memset(dp,0,sizeof(dp));
    f2();
    //cout <<qmod(2,5)<<endl;
    while(~scanf("%d%d",&x,&y))
    {
        printf("%lld\n",dp[x][y]);
    }
}