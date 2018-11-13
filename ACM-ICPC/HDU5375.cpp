// Wrote by MenYifan on 2016-04-20 21:11:02
// Exe.Time 452ms Exe.Memory 3796K
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
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char a[200005]={};
int w[200005]={};
int dp[200005][3]={};
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while (t--) {
        
        int n;
        scanf("%s",a+1);
        n=strlen(a+1);
        for (int i=1; i<=n; i++) {
            scanf("%d",&w[i]);
        }
        dp[0][1]=-INF;
        for (int i=1; i<=n; i++) {
            if (a[i]=='0') {
                dp[i][1]=-INF;
                dp[i][0]=max(dp[i-1][0], dp[i-1][1]+w[i]);
            }
            else if (a[i]=='1'){
                dp[i][0]=-INF;
                dp[i][1]=max(dp[i-1][1], dp[i-1][0]+w[i]);
            }
            else{
                dp[i][0]=max(dp[i-1][0], dp[i-1][1]+w[i]);
                dp[i][1]=max(dp[i-1][1], dp[i-1][0]+w[i]);
            }
        }
        printf("Case #%d: ",++cas);
        cout<<max(dp[n][0], dp[n][1])<<endl;
    }
    return 0;
}