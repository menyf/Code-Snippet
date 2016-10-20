// Wrote by MenYifan on 2016-03-23 22:22:39
// Exe.Time 1825ms Exe.Memory 40724K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (j == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 1000005
#define mod 1000000007
int num[maxn];
int vis[maxn][9];
void init()
{
    for(int i=2; i<maxn; i++)
    {
        if(num[i]==0)
        {
            for(int j=i; j<maxn; j+=i)
            {
                num[j]++;
            }
        }
    }
}
int main()
{
    init();
    for(int i=2;i<maxn;i++)
    {
        if(num[i]==6)
        {
            vis[i][1]=vis[i-1][1]+1;
            vis[i][4]=vis[i-1][4];
            vis[i][5]=vis[i-1][5];
            vis[i][6]=vis[i-1][6]+1;
            vis[i][3]=vis[i-1][3]+1;
            vis[i][2]=vis[i-1][2]+1;
            vis[i][7]=vis[i-1][7];
        }
        else if(num[i]==4)
        {
            vis[i][4]=vis[i-1][4]+1;
            vis[i][2]=vis[i-1][2]+1;
            vis[i][1]=vis[i-1][1]+1;
            vis[i][5]=vis[i-1][5];
            vis[i][3]=vis[i-1][3];
            vis[i][6]=vis[i-1][6];
            vis[i][7]=vis[i-1][7];
        }
        else{

            for(int j=1;j<=7;j++)
            {
                if(j==num[i]||j==1)
                   vis[i][j]=vis[i-1][j]+1;
                else
                    vis[i][j]=vis[i-1][j];
            }
        }

    }

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r,ans=0;
        scanf("%d %d",&l,&r);
        int v[10];
        memset(v,0,sizeof(v));
        for(int i=1; i<=7; i++)
        {
            v[i]=vis[r][i]-vis[l-1][i];
            if(v[i]>=2) ans=i;
        }
        cout<<ans<<endl;
    }

}