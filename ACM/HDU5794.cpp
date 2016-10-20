//参考题解: http://www.itdadao.com/articles/c15a172401p0.html

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
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int fcnt=120005;
const long long M=110119;
long long fac[fcnt];
long long inv[fcnt];
struct Block{
    ll x, y;
}block[105];
bool cmp(Block a, Block b){
    if (a.x==b.x)
        return a.x<b.x;
    else
        return a.y<b.y;
}
ll powMod(ll a, ll b){
    ll ans =1;
    for( a%=mod; b; b>>=1, a = a * a % mod)
        if(b&1)  ans = ans * a % mod;
    return  ans;
}
void init(){
    fac[0] = 1;
    for(int i = 1; i < mod; i++)
        fac[i] = fac[i-1] * i % mod;
    inv[mod - 1]=powMod( fac[mod - 1], mod - 2);
    for(int i = mod-2; i >= 0 ; i--)
        inv[i] = inv[i+1] * (i+1) % mod;
}
ll C(ll n, ll m){
    return  m > n ? 0 : fac[n] * inv[m] % mod * inv[n-m] % mod;
}
ll Lucas(ll n, ll m){// n>m
    if (n<0||m<0||n<m)
        return 0;
    return  m ? (C(n%mod , m%mod) * Lucas(n/mod, m/mod)) % mod : 1;
}
ll dp[105];
int main(){
    init();
    int cas = 1;
    ll n, m, r, dis, step,nn,mm;
    while (scanf("%lld%lld%lld",&n,&m,&r)!=EOF) {
        for (int i=1; i<=r; i++)
            scanf("%lld%lld",&block[i].x,&block[i].y);
        block[r+1].x = n;
        block[r+1].y = m;
        sort(block+1, block+1+r, cmp);
        
        for (int i=1; i<=r+1; i++) {
            dp[i]=0;
            dis = ( block[i].x - 1 ) + ( block[i].y - 1 ) ;
            if (dis % 3) continue;
            step = dis / 3 ;
            nn =  ( block[i].x - 1 - step ) + ( block[i].y - 1 - step);
            mm = block[i].x - 1 - step;
            dp[i] = Lucas(nn, mm);
            
            for (int j=1; j<i; j++) {
                dis = ( block[i].x - block[j].x ) + ( block[i].y - block[j].y ) ;
                if (dis % 3 || block[j].x > block[i].x || block[j].y > block[i].y) continue;
                step = dis / 3 ;
                nn =  ( block[i].x - block[j].x - step ) + ( block[i].y - block[j].y - step);
                mm = block[i].x - block[j].x - step;
                dp[i] = ((dp[i] - Lucas(nn, mm) * dp[j] + mod) % mod + mod ) %mod;
            }
        }
        
        
        printf("Case #%d: %lld\n",cas++,dp[r+1]);
    }
    return 0;
}
