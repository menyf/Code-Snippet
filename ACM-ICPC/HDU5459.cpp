// Wrote by MenYifan on 2016-08-27 16:01:39
// Exe.Time 15ms Exe.Memory 9464K
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
using namespace std;
long long qian[210000];
long long hou[210000];
long long len[210000];
long long num[210000];
long long ans[210000];
const long long mod=530600414LL;
int main ()
{
    int cas=1;
    qian[1]=1;hou[1]=2;len[1]=3;num[1]=1;ans[1]=0;
    qian[2]=3;hou[2]=2;len[2]=5;num[2]=1;ans[2]=0;
    for (int i=3;i<=201314;i++)
    {
        len[i]=(len[i-1]+len[i-2])%mod;
        num[i]=(num[i-1]+num[i-2])%mod;
        qian[i]=(qian[i-2]+qian[i-1]+num[i-1]*len[i-2]%mod)%mod;
        hou[i]=(num[i]*len[i]-qian[i]+mod)%mod;
        ans[i]=(ans[i-1]+ans[i-2])%mod+qian[i-1]*num[i-2]%mod+hou[i-2]*num[i-1]%mod;
        ans[i]=ans[i]%mod;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        scanf("%d",&x);
        //cout <<qian[x-2]<<' '<<hou[x-2]<<' '<<len[x-2]<<' ';
        printf("Case #%d: %I64d\n",cas++,ans[x-2]);
    }
}
