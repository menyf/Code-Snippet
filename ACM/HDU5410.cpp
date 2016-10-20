// Wrote by MenYifan on 2016-05-12 00:42:45
// Exe.Time 140ms Exe.Memory 1576K
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
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int dp[2005];
int main() {
    int t,n,m,w,a,b;
    scanf("%d",&t);
    while (t--) {
        Memset(dp, 0);
        scanf("%d%d",&m,&n);
        
        for (int i=1; i<=n; i++) {
            scanf("%d%d%d",&w,&a,&b);
            
            for (int i=m; i>=w; i--) {
                dp[i]=max(dp[i], dp[i-w]+a+b);
            }
            
            for (int i=w; i<=m; i++) {
                dp[i]=max(dp[i], dp[i-w]+a);
            }
        }
        
        printf("%d\n",dp[m]);
    }
    return 0;
}