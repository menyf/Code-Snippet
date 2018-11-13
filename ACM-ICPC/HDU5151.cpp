// Wrote by MenYifan on 2016-08-12 21:01:23
// Exe.Time 31ms Exe.Memory 1764K
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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll dp[maxn][maxn];
int a[maxn];
long long c[maxn][maxn]= {};
void cinit()
{
    for(int i=0; i<maxn; i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1; j<i; j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
}

int main(){
    
    cinit();
    int n;
    while (scanf("%d",&n)!=EOF) {
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        for (int i=1; i<=n; i++) {
            scanf("%d",a+i);
        }
        for (int i=1; i<=n; i++) {
            dp[i][i]=1;
        }
        for (int i=1; i<=n-1; i++) {
            dp[i][i+1]=2;
        }
        
        for (int len = 2; len < n; len ++) {
            for (int l=1,r=l+len; r<=n; l++,r++) {
                for (int k = l; k<=r; k++) {
                    if (k==l)
                        dp[l][r] += dp[l+1][r], dp[l][r] %= mod;
                    else if (k==r)
                        dp[l][r] += dp[l][k-1], dp[l][r] %= mod;
                    else if (a[k-1] == a[k+1])
                        dp[l][r] = (dp[l][r] + dp[l][k-1] * dp[k+1][r] % mod * c[r-l][k-l] % mod) % mod;
                }
            }
        }
//        for (int i=1; i<=n; i++) {
//            for (int j=1; j<=n; j++) {
//                printf("%lld ",dp[i][j]);
//            }
//            putchar(10);
//        }
//        
        cout<<dp[1][n]<<endl;
    }
}