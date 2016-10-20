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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int dp[1005][1005][3][3];
int a[1005];
void add(int &x,int y){
    x = ( x + y ) % mod;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n ,m;
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
            scanf("%d",a+i);
        
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0]=1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                for (int x = 0; x<3; x++) {
                    for (int y=0; y<3; y++) {
                        
                        // 选
                        if (j>=a[i])
                            add(dp[i][j][x][y], dp[i-1][j-a[i]][x][y]);
                        
                        // 不选
                        add(dp[i][j][x][y], dp[i-1][j][x][y]);
                        
                        // 必选
                        if (x>=1&&j>=a[i])
                            add(dp[i][j][x][y], dp[i-1][j-a[i]][x-1][y]);
                        
                        // 必不选
                        if (y>=1)
                            add(dp[i][j][x][y], dp[i-1][j][x][y-1]);

                    }
                }
            }
        }
        ll ans = 0;
        for (int i=0; i<=m; i++)
            ans += dp[n][i][2][2];
        cout<<ans*4%mod<<endl;
    }
}
