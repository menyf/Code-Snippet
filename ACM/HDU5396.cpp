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
#include <deque>
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
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int n;
ll dp[105][105],C[105][105],F[105];
char s[105];
void init(){
    F[0]=1;
    for (int i=1; i<=100; i++){
        F[i]=F[i-1]*i%mod;
    }
    
    
    C[0][0]=1;
    for (int i=1; i<=100; i++) {
        C[i][0]=1;
        for (int j=1; j<=i; j++) {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int main(){
    init();
    while (scanf("%d",&n)!=EOF) {
        Memset(dp, 0);
        for (int i=1; i<=n; i++)
            scanf("%lld",&dp[i][i]);
        scanf("%s",s+1);//1~n-1
        
        ll sum;
        for (int len=2; len<=n; len++) {
            for (int l=1,r=l+len-1; r<=n; l++,r++) {
                for (int pos=l; pos<r; pos++) {
                    if (s[pos]=='+')
                        sum=(dp[l][pos]*F[r-pos-1]%mod+dp[pos+1][r]*F[pos-l]%mod)%mod;
                    else if (s[pos]=='-')
                        sum=(dp[l][pos]*F[r-pos-1]%mod-dp[pos+1][r]*F[pos-l]%mod)%mod;
                    else
                        sum=dp[l][pos]*dp[pos+1][r]%mod;
                    
                    dp[l][r]=(dp[l][r]+sum*C[r-l-1][pos-l])%mod;
                }
            }
        }
        
        cout<<(dp[1][n]+mod)%mod<<endl;
    }
}

