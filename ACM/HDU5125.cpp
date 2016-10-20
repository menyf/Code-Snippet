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
const int mod=110119;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct node{
    int len, cost;
}dp[2005];
int a[2005];
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m,isEven;
        scanf("%d%d",&n,&m);
        for (int i=1; i<=2*n; i++) scanf("%d",&a[i]);
        
        dp[1].len = 1; dp[1].cost = 0;
        dp[2].len = 1; dp[2].cost = 1;
        
        int pos = 1;
        for (int i=3; i<=2*n; i++) {
            isEven = i % 2 ? 0 : 1;
            dp[i].len= 1;
            dp[i].cost = isEven;
            for (int j=i-1-isEven; j>=1; j--) {
                if (a[j]<a[i]) {
                    if (dp[j].len + 1 > dp[i].len) {
                        dp[i].len = dp[j].len + 1;
                        dp[i].cost = dp[j].cost + isEven;
                    }
                    else if (dp[i].len == dp[j].len + 1 && dp[i].cost > dp[j].cost + isEven)
                        dp[i].cost = dp[j].cost + isEven;
                }
            }
            if (dp[i].len > dp[pos].len && dp[i].cost <= m) pos = i;
        }
        printf("%d\n",dp[pos].len);
    }
}
