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
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define pii pair<int,int>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
map<pii, int>mp;
struct point {
    int x,y;
}p[1050];
bool cmp(point a,point b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}
ll qpow(ll a,ll n){
    ll rt=1;
    while (n) {
        if (n&1) {
            rt=rt*a%mod;
        }
        n>>=1;
        a=a*a%mod;
    }
    return rt;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        ll ans=0;
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        sort(p, p+n, cmp);
        for (int i=0; i<n; i++) {
            mp.clear();
            int cnt=0;
            for (int j=i+1; j<n; j++) {
                if (p[i].x==p[j].x&&p[i].y==p[j].y) {
                    cnt++;
                    continue;
                }
                int tmpx = p[i].x - p[j].x;
                int tmpy = p[i].y - p[j].y;
                int gcd = __gcd(tmpx, tmpy);
                mp[make_pair(tmpx/gcd, tmpy/gcd)]++;
            }
            ll base = qpow(2, cnt);
            ans = (ans+base-1)%mod;
            for (map<pii, int>::iterator it=mp.begin(); it!=mp.end(); it++) {
                ll tmp = it->second;
                ans += (qpow(2, tmp)-1)*base%mod;
                ans %= mod;
            }
        }
        cout<<ans<<endl;
    }
}
