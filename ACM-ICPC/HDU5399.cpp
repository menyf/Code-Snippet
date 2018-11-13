// Wrote by MenYifan on 2016-05-04 20:22:22
// Exe.Time 46ms Exe.Memory 1660K
#pragma comment(linker, "/STACK:10240000000,10240000000")///?????c++???g++???????????
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1e9
#define MIN 1e-8
#define LL long long
#define mys 1000000007
#define debug2 puts("****")
#define blank puts("")
#define pf printf
#define sf scanf
#define mem(a,b) memset(a, b, sizeof(a))
#define memc(a) memset(a, '\0', sizeof(a))
#define debug(x) (cout<<"--- "<<(x)<<" ---"<<endl)
LL a[105][105];
LL f[105];
LL n,m;
LL ans=1;
LL cnt=0;
void init()
{
    f[0]=1;
    for(int i=1; i<=100; i++)
        f[i]=f[i-1]*i%mys;
}
void output()
{
    for(LL i=1; i<cnt; i++)
        ans=ans*f[n]%mys;
}
void judge()
{
    for(int j=1;j<=n;j++){
        int i=m-1;int tmp=a[m][j];
        while(i>=1){
            tmp=a[i--][tmp];
        }
        if(tmp!=j){
            ans=0;
            break;
        }
    }
}
int main()
{
    init();
    while(scanf("%I64d%I64d",&n,&m)!=EOF)
    {   ans=1;
        cnt=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%I64d",&a[i][1]);
            if(a[i][1]==-1)
                cnt++;
            else
            {
                for(int j=2; j<=n; j++)
                {
                    scanf("%I64d",&a[i][j]);
                    for(int k=j-1; k; k--)
                        if(a[i][j]==a[i][k])
                        {
                            ans=0;
                            break;
                        }
                }
            }
        }
        if(cnt>0)
        {
            output();
            printf("%I64d\n",ans);
        }
        else
        {
            judge();
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
