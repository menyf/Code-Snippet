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
#pragma comment(checker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn],dp[maxn];
int main(){
    int T,n,tmp;
    scanf("%d",&T);
    for (int cas = 1; cas<=T; cas++) {
        scanf("%d",&n);
        int acnt=0,cnt=0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&tmp);
            if (tmp==0)
                cnt++;
            else
                a[acnt++]=tmp-cnt;
        }
        if (cnt==n) {
            printf("Case #%d: %d\n",cas,cnt);
        }
        else{
            int len = 1;
            dp[len]=a[0];
            for (int i=1; i<acnt; i++) {
                if (a[i]>dp[len]) {
                    dp[++len]=a[i];
                }
                else{
                    int pos = lower_bound(dp+1, dp+len+1, a[i])-dp;
                    dp[pos]=a[i];
                }
            }
            printf("Case #%d: %d\n",cas,cnt+len);
        }
    }
}
