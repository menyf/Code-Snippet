//BestCoder #63 div2 C
//HDU 5569
/*

少一个图呢还！

(HDU 5569)[http://acm.hdu.edu.cn/showproblem.php?pid=5563]
(BestCoder #63C)[http://bestcoder.hdu.edu.cn/contests/contest_chineseproblem.php?cid=650&pid=1003]

题目大意，一个矩阵，从(1, 1)走到(n, m)，保证(n+m)%2=1，将走过的这m+n-1个数组成一个新的序列，按照a1*a2+a3*a4...a(2k-1)*a2k计算贡献，求最小贡献。

解析：DP
因为算的这个贡献都是偶数个数字，所以经历过的点数量为奇数的话对dp[n][m]没有影响。对于每一个ai,j，都可以看作从四个方向而来，具体如图。剩下的看代码好了。
其实这题挺遗憾的，这也算是自己第一次手写dp，还是道C题，只是在上方来和左方来两个方向的时候应该是">=3"，做比赛的时候写的是">3"，因此wa了，找了半天找不出来放弃了。洗澡的时候突然想到了问题。加油吧，争取早日进div1。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100050;
int mp[1005][1005];
int dp[1005][1005];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&mp[i][j]);

        memset(dp,0,sizeof(dp));

        //构造第一行
        dp[1][2]=mp[1][1]*mp[1][2];
        for(int i=4; i<=m; i+=2)
            dp[1][i]=dp[1][i-2]+mp[1][i-1]*mp[1][i];

        //构造第一列
        dp[2][1]=mp[1][1]*mp[2][1];
        for(int i=4; i<=n; i+=2)
            dp[i][1]=dp[i-2][1]+mp[i-1][1]*mp[i][1];


        for(int i=2; i<=n; i+=1)
        {
            for(int j=2; j<=m; j+=1)
            {
                if((i+j)%2==0) continue;

                //从左上角来
                dp[i][j]=dp[i-1][j-1]+min(mp[i][j]*mp[i][j-1],mp[i][j]*mp[i-1][j]);

                //从上方来
                if(i>=3) dp[i][j]=min(dp[i][j],dp[i-2][j]+mp[i][j]*mp[i-1][j]);

                //从左边来
                if(j>=3) dp[i][j]=min(dp[i][j],dp[i][j-2]+mp[i][j]*mp[i][j-1]);
            }
        }

        printf("%d\n",dp[n][m]);
    }
}

