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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100001+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll bin[maxn];
ll lowbit(ll x){
    return x&(-x);
}
void update(ll pos, ll val){
    while (pos<maxn) {
        bin[pos]+=val;
        pos += lowbit(pos);
    }
}
ll sum (ll pos){
    ll ret = 0;
    while (pos > 0) {
        ret += bin[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
ll a[maxn],tmp[maxn],b[maxn],ans,k,cnt;
int in[maxn];
vector<int> G[maxn];
void dfs(int u){
    ll now = k / a[u];
    ll pos = upper_bound(tmp+1, tmp+1+cnt, now) - tmp;
    ans += sum(pos-1);
    update(b[u], 1);
    for (int i = 0; i<G[u].size(); i++) {
        int v = G[u][i];
        dfs(v);
    }
    update(b[u], -1);
}
void solve(){
    // init
    ans = 0;
    memset(bin, 0, sizeof(bin));
    memset(in, 0, sizeof(in));
    
    int n;
    scanf("%d%lld",&n,&k);
    for (int i = 1; i<=n; i++) {
        scanf("%lld",&a[i]);
        G[i].clear();
        tmp[i] = a[i];
    }
    for (int i = 1; i<n; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        in[v]++;
    }
    
    // 离散化
    sort(tmp+1, tmp+1+n);
    cnt = unique(tmp+1, tmp+1+n) - tmp - 1;
    for (int i = 1; i<=n ; i++) {
        b[i] = lower_bound(tmp+1, tmp+1+cnt, a[i]) - tmp;
    }
    
    int rt= 0;
    for (int i = 1; i<=n; i++) {
        if (in[i]==0) {
            rt = i;
            break;
        }
    }
    dfs(rt);
    cout<<ans<<"\n";
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}
