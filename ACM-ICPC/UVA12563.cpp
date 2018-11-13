// Wrote by MenYifan on 2016-08-07 10:55:17
// Exe.Time 0ms Exe.Memory 0K
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
const int maxn=180*50+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn],dp[maxn];
int main(){
    int T,n,t,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&t);
        for (int i=1; i<=n; i++) {
            scanf("%d",a+i);
        }
        Memset(dp, 0x8f);
        dp[0]=0;
        for (int i=1; i<=n; i++) {
            for (int j = t-1; j>=a[i]; j--) {
                dp[j] = max(dp[j], dp[j-a[i]]+1);
            }
        }
        
        int ans = t-1;
        for (int i=t-1; i>=0; i--) {
            if (dp[i]>dp[ans]) {
                ans = i;
            }
        }
        printf("Case %d: %d %d\n",cas++,dp[ans]+1,ans+678);
    }
}