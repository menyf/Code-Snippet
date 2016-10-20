// Wrote by MenYifan on 2016-08-22 21:11:23
// Exe.Time 78ms Exe.Memory 1600K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
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

const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

const int maxn=1000005+5;
ll factor[maxn];
vector<ll> v;
int main(){
    ll n;
    int cas= 1;
    while (scanf("%lld",&n)!=EOF) {
        v.clear();
        ll rt = sqrt(n) + 0.5;
        int cnt=1;
        factor[0]=1;
        for (ll i=2; i<=rt; i++) {
            if (n%i==0) {
                factor[cnt++] = i;
                factor[cnt++] = n / i;
            }
        }
        ll ans = 0;
        for (int i=0; i<cnt; i++) {
            if ((n ^ factor[i]) < n && (n ^ factor[i]) > 0 && __gcd(n, n ^ factor[i]) == factor[i])
            {
                v.push_back(n^factor[i]);
                ans++;
            }
        }
        sort(v.begin(), v.end());
        printf("Case #%d:\n",cas++);
        printf("%lld\n",ans);
        if (ans) {
            int sz=v.size();
            for (int i=0; i<sz; i++) {
                printf("%lld%c",v[i],rt(sz-1));
            }
        }
        else
            puts("");
    }
}