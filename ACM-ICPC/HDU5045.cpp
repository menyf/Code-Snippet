// Wrote by MenYifan on 2016-09-01 15:28:26
// Exe.Time 62ms Exe.Memory 1800K
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<iostream>
using namespace std;
double dp[15][1<<10];
double a[11][1010];
double f(int n,int m,int be)
{
  memset(dp,0,sizeof(dp));
    for (int i = 1; i <=m; i++)
    {
         for (int k = 0; k < n; k++)
        {
           for (int j = 0; j < (1 << n); j++)
            {
                if(!((j >> k) & 1))
                {
                    dp[i][j+(1<<k)] = max(dp[i][j+(1<<k)], dp[i-1][j] + a[k][i+be-1]);
                    //cout <<dp[i][j+(1<<k)] <<'b'<<endl;
                }
            }
        }

    }
    //cout <<dp[m][(1<<n)-1]<<'a'<<endl;
    return dp[m][(1<<n)-1];
}

int main ()
{
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        double sum=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                scanf("%lf",&a[i][j]);
            }
        }
        for (int i=0;i<m/n;i++)
        {
            sum+=f(n,n,i*n);
           //cout <<i;
        }
        //cout <<'b';
        sum+=f(n,m%n,m-m%n);
        printf("Case #%d: %.5f\n",cas++,sum);
    }
}