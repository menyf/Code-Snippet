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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char a[maxn],b[maxn];
int dp[maxn],jump[maxn];
int main(){
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++) {
        scanf("%s%s",a+1,b+1);
        int len1 = strlen(a+1);
        int len2 = strlen(b+1);
        int j=0;
        for (int i=2; i<=len2; i++) {
            while (j&&b[i]!=b[j+1]) {
                j = jump[j];
            }
            if (b[i]==b[j+1]) {
                j++;
            }
            jump[i]=j;
        }
        j = 0;
        dp[0]=1;
        for (int i=1; i<=len1; i++) {
            while (j&&a[i]!=b[j+1]) {
                j=jump[j];
            }
            dp[i]=dp[i-1];
            if (a[i]==b[j+1]) {
                j++;
            }
            if (j==len2) {
                dp[i]+=dp[i-len2];
                dp[i]%=mod;
                j=jump[j];
            }
        }
        printf("Case #%d: %d\n",cas,dp[len1]);
    }
}
