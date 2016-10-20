#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=30+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int x[35][35];
ll dp[maxn][maxn][1900];
int main(){
    int T,cas=1,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                scanf("%d",&x[i][j]);
            }
        }
        
        Memset(dp, -1);
        dp[1][1][x[1][1]] = x[1][1] * x[1][1];

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (i>=2) {
                    for (int k = x[i][j]; k<1800; k++) {
                        if (dp[i-1][j][k-x[i][j]]!=-1) {
                            if (dp[i][j][k]==-1) {
                                dp[i][j][k] = dp[i-1][j][k-x[i][j]] + x[i][j] * x[i][j];
                            }
                            else{
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k-x[i][j]] + x[i][j] * x[i][j]);
                            }
                        }
                    }
                }
                if (j>=2) {
                    for (int k = x[i][j]; k<1800; k++) {
                        if (dp[i][j-1][k-x[i][j]]!=-1) {
                            if (dp[i][j][k]==-1) {
                                dp[i][j][k] = dp[i][j-1][k-x[i][j]] + x[i][j] * x[i][j];
                            }
                            else{
                                dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k-x[i][j]] + x[i][j] * x[i][j]);
                            }
                        }
                    }
                }
            }
        }
        
        ll ans = INF;
        for (int i=0; i<1800; i++) {
            if (dp[n][m][i]!=-1) {
                ll tmp = (n+m-1)*dp[n][m][i] - i * i;
                ans = min(ans, tmp);
            }
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
