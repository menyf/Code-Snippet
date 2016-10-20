// Wrote by MenYifan on 2016-09-03 15:55:41
// Exe.Time 1466ms Exe.Memory 54780K
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
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll bin[maxn],nn;
ll lowbit(ll x){
    return x&(-x);
}
void update(ll pos,ll val){
//    debug2(pos,val);
    while (pos<maxn) {
        bin[pos]+=val;
        pos+=lowbit(pos);
    }
}
ll sum(ll pos){
    ll ans=0;
    while (pos>0) {
        ans+= bin[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
ll num[maxn],lsh[maxn],a[maxn],n;
ll discrete(){
    memcpy(lsh, num, sizeof(lsh));
    stable_sort(lsh+1, lsh+1+n);
    ll cnt=unique(lsh+1, lsh+1+n)-lsh-1;
    for (ll i=1; i<=n; i++)
        a[i]=lower_bound(lsh+1, lsh+cnt+1, num[i])-lsh;
    return cnt;
}
ll l[maxn],r[maxn];
int main(){
    scanf("%lld",&n);
    for (ll i=1; i<=n; i++) {
        scanf("%lld",&num[i]);
    }
    nn = discrete();
    memset(bin, 0, sizeof(bin));
    for (ll i=1; i<=n; i++) {
        update(a[i], 1);
        l[i] = sum(a[i]) - sum(a[i]-1);
    }
    memset(bin, 0, sizeof(bin));
    for (ll i=n; i>=1; i--) {
        update(a[i], 1);
        r[i] = sum(a[i]) - sum(a[i] - 1);
    }
//    for (int i=1; i<=n; i++) {
//        printf("%lld ",l[i]);
//    }
//    puts("");
//    for (int i=1; i<=n; i++) {
//        printf("%lld ",r[i]);
//    }
//    puts("");
    
    memset(bin, 0, sizeof(bin));
    ll ans= 0 ;
    for (ll i=n; i>=1; i--) {
        ll tmp = sum(l[i]-1);
//        debug(tmp);
        ans += tmp;
        update(r[i], 1);
    }
    cout<<ans<<"\n";
}