// Wrote by MenYifan on 2016-08-31 20:19:51
// Exe.Time 421ms Exe.Memory 7844K
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
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=30+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll dp[20][20][2000];    //pos pivot sum
int num[20];
ll dfs(int pos, int pivot,int sum, bool limit){
    if (pos == 0)
        return sum == 0;
    
    if (!limit && dp[pos][pivot][sum]!=-1)
        return dp[pos][pivot][sum];
    
    int mx = limit ? num[pos] : 9;
    ll ret = 0;
    for (int i=0; i<=mx; i++) {
        int newSum = sum + (pos - pivot) * i;
        if (newSum >= 0) {
            ret += dfs(pos-1, pivot, newSum , limit && i==mx);
        }
    }
    if (!limit) {
        dp[pos][pivot][sum] = ret;
    }
    return ret;
}
ll solve(ll x){
    Memset(dp, -1);
    int pos = 0;
    while (x!=0) {
        num[++pos] = x % 10;
        x/=10;
    }
    ll ans = 0;
    for (int i=1; i<=pos; i++) {
        ans += dfs(pos, i, 0, 1);
    }
    return ans - (pos - 2); //remove the count of '0000', '000', '00' when pos==5
}
int main(){
    ll l,r;
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&l,&r);
        cout<<solve(r) - solve(l-1)<<endl;
    }
    return 0;
}