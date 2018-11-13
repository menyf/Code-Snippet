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
#define pb push_back
#define mp make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : "<<x<<" "<<y<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100010+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

int a[maxn],dp[maxn],ans[maxn];
int LIS(int n) {
    int len = 1;
    dp[1] = a[0]; //初始化：长度为1的LIS末尾为d[0]
    ans[0]=1;
    for (int i = 1; i < n; i++) {
        int pos = lower_bound(dp + 1, dp + len + 1, a[i]) - dp; //找到插入位置
        ans[i]=pos;
        dp[pos] = a[i];
        len = max(len, pos);
    }
    return len;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        LIS(n);
        for (int i=0; i<n; i++) {
            printf("%d%c",ans[i],i==n-1?'\n':' ');
        }
    }
}
