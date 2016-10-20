// Wrote by MenYifan on 2016-07-20 22:17:33
// Exe.Time 343ms Exe.Memory 37364K
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
#define mp make_pair
#define pb push_back
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int num[3005*3005];
int a[3005];
int c[3005];
int dp[3005][3005];
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        Memset(dp, 0);
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            scanf("%d",&num[i]);
        }
        sort(num+1, num+1+n);
        
        int cnt=1;
        a[cnt]=num[1];
        c[cnt]=1;
        for (int i=2; i<=n; i++) {
            if (num[i]==num[i-1]) {
                c[cnt]++;
            }
            else{
                a[++cnt]=num[i];
                c[cnt]=1;
            }
        }
        
        for (int i=1; i<=cnt; i++) {
            dp[i][i]=c[i];
        }
        
        int ans=0;
        for (int i=1; i<=cnt; i++) {
            int tmp = dp[i][i];
            ans=max(ans, tmp);
            int k = i;
            for (int j=i+1; j<=cnt; j++) {
                for (; k>=1&&a[i]-a[k]<=a[j]-a[i]; k--) {
                    tmp=max(tmp, dp[k][i]+1);
                }
                dp[i][j]=tmp;
                ans=max(ans, tmp);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}