// Wrote by MenYifan on 2016-08-29 15:27:15
// Exe.Time 62ms Exe.Memory 1608K
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
const int maxn=500+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll dp[maxn][2][2][2],n,m;
int dig[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void add(ll &x,ll y){
    x += y;
    if (x > m) x -= m;
}
ll dfs(ll left,int carry,int B,int C){
    ll &now = dp[left][carry][B][C];
    if (now != -1) {
        return now;
    }
    if (left == 0) {
        if (!carry && !B && !C) {
            return now = 1;
        }
        else
            return now = 0;
    }
    now = 0;
    if (B && C) {
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                int sum = dig[i] + dig[j] + dig[(i+j+carry)%10];
                if (sum > left) {
                    continue;
                }
                int nxt = i + j + carry >= 10;
                add(now, dfs(left-sum, nxt, 1, 1));
                if (i) {
                    add(now, dfs(left-sum, nxt, 0, 1));
                }
                if (j) {
                    add(now, dfs(left-sum, nxt, 1, 0));
                }
                if (i&&j) {
                    add(now, dfs(left-sum, nxt, 0, 0));
                }
                
            }
        }
    }
    else if (B){
        for (int i=0; i<10; i++) {
            int sum = dig[i] + dig[(i+carry)%10];
            if (sum > left) {
                continue;
            }
            int nxt = i + carry >= 10;
            add(now, dfs(left-sum, nxt, 1, 0));
            if (i) {
                add(now, dfs(left-sum, nxt, 0, 0));
            }
        }
    }
    else if (C){
        for (int i=0; i<10; i++) {
            int sum = dig[i] + dig[(i+carry)%10];
            if (sum > left) {
                continue;
            }
            int nxt = i + carry >= 10;
            add(now, dfs(left-sum, nxt, 0, 1));
            if (i) {
                add(now, dfs(left-sum, nxt, 0, 0));
            }
        }
    }
    else{
        if (carry && left==dig[1]) {
            now = 1;
        }
    }
    return now;
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&n,&m);
        Memset(dp, -1);
        printf("Case #%d: %lld\n",cas++,dfs(n-3, 0, 1, 1));
    }
}