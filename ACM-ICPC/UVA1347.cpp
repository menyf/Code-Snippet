// Wrote by MenYifan on 2016-07-24 08:34:19
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=50000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int x[1005],y[1005];
double dp[1005][1005];
double dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&x[i],&y[i]);
        }
        
        for (int i=1; i<=n; i++) {
            dp[n-1][i]=dis(n-1,n)+dis(i,n); //???????
        }
        
        for (int i=n-2; i>=2; i--) {
            for (int j=1; j<i; j++) {
                dp[i][j] = min(dp[i+1][j]+dis(i,i+1),dp[i+1][i]+dis(j,i+1));
            }
        }
        
        printf("%.2f\n",dp[2][1]+dis(1,2));
    }
}