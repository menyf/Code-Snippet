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
const int maxn=2000+5;
const int mod=1000000007;
const ll INF=1e18+10;
const double eps=1e-8;
double dp[maxn][20];
int cnt[maxn];
int main(){
    cnt[0]=0;
    cnt[1]=1;
    for (int i=2; i<maxn; i++) {
        cnt[i] = cnt[ i / 2 - 1 ] + 1;
    }
    for (int i=1; i<maxn; i++) {
        dp[i][1] = (i+1)*(i+2)/2 - 1;
        if (i!=1) {
            cnt[i]++;
        }
        for (int j=2; j<=cnt[i]; j++) {
            dp[i][j] = INF;
            for (int k = 1; k<i; k++) {
                dp[i][j] = min (dp[i][j], dp[k-1][j-1]+ dp[i - k][j] + i + 1);
            }
        }
        for (int j=cnt[i]+1; j<20; j++) {
            dp[i][j] = dp[i][cnt[i]];
        }
    }
    int w,k ;
    while (~scanf("%d%d",&k, &w)) {
        printf("%.6f\n",dp[k][min(19, w)]/(k+1));
    }
}
