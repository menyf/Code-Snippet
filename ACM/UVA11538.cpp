// Wrote by MenYifan on 2015-11-16 13:14:27
// Exe.Time 0ms Exe.Memory 0K
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll n,m;
    while (scanf("%lld %lld",&m,&n),n&&m) {
        long long ans=0;
        if (m>n) swap(m, n);
        ans=n*m*(n+m-2)+2*((m-1)*(2*m-1)*m/3-m*(m-1)+(n-m+1)*m*(m-1));
        printf("%lld\n",ans);
    }
}