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
const int maxn=50000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll rb[maxn],rs[maxn],lb[maxn],ls[maxn];
ll a[maxn],t[maxn],c[maxn];
ll n,nx,sx,ans,tmp;
ll lowbit(ll x){
    return x&(-x);
}
void update(ll pos,ll val){
    while (pos<=n) {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
ll sum(ll pos){
    ll ans=0;
    while (pos>0) {
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    while (scanf("%lld",&n)!=EOF) {
        for (ll i=1; i<=n; i++) {
            scanf("%lld",&tmp);
            a[i]=t[i]=tmp;
        }

        nx = sx = 0;
        ans=0;
        
        sort(t+1, t+1+n);
        ll cnt=unique(t+1, t+n+1)-t-1;
        for (ll i=1; i<=n; i++){
            a[i]=lower_bound(t+1, t+1+cnt, a[i])-t;
        }
        
        memset(c, 0, sizeof(c));
        for (ll i = 1 ; i<=n; i++) {
            update(a[i], 1);
            lb[i]= i - sum(a[i]);   //左边大于a[i]的数的个数
            ls[i] = sum(a[i]-1);    //左边小于a[i]的数的个数
            sx +=ls[i];  //顺序数的累加
        }
        memset(c, 0, sizeof(c));
        for (ll i = n; i >= 1; i--) {
            update(a[i], 1);
            rs[i] = sum(a[i]-1);    //右边小于a[i]的数的个数
            rb[i] = n - sum(a[i]) - i + 1;  //右边大于a[i]的数的个数
            nx += rs[i]; //逆序数的累加
        }
        
        ans = nx * sx;
        for (ll i = 1; i <= n; i++)
            ans -= ( rb[i] + ls[i] ) * ( rs[i] + lb[i] );
        
        cout<<ans<<endl;
    }
}
