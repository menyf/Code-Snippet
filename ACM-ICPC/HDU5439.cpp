// Wrote by MenYifan on 2016-08-25 21:17:25
// Exe.Time 31ms Exe.Memory 11892K
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
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=438744;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[maxn+5],b[maxn+5],ans[maxn+5];
void Init(){
    a[1] = 1, a[2] = 2, a[3] = 2;
    b[1] = 1, b[2] = 3;
    int idx = 4;
    for (int i=3; i<maxn; i++) {
        for (int j = 0; j<a[i]; j++) {
            a[idx++] = i;
            if (idx>maxn) break;
        }
        if (idx>maxn) break;
    }
    for (int i=3; i<maxn; i++) {
        b[i] = b[i-1] + a[i];
        if (b[i] > 1e9) {break;}
    }
    ans[1] = 1;
    for (int i=2; i<maxn; i++) {
        ll l = b[i-1]+ 1;
        ll r = b[i];
        ans[i] = (ans[i-1] + ( r - l + 1 )  * ( l + r ) / 2 %mod*i%mod) % mod;
    }
    
    return;
}
int main(){
    Init();
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n;
        scanf("%lld",&n);
        ll id = lower_bound(b+1, b+maxn, n) - b;
        ll l = b[id-1] + 1;
        ll r = n;
        cout<<(ans[id-1]+(r-l+1)*(l+r)/2%mod*id%mod)%mod<<'\n';
    }
    return 0;
}