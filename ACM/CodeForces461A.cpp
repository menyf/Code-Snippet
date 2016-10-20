// Wrote by MenYifan on 2016-09-05 19:34:38
// Exe.Time 78ms Exe.Memory 7836K
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
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn = 1e6 + 10;
ll a[maxn];
int main(){
    int n;
    ll ans = 0,sum = 0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
        ans += a[i];
    }
    
    if (n==1) {
        cout<<ans<<endl;
        return 0;
    }
    
    ans *= 2;
    sort(a, a+n);
    sum = a[n-1];
    for (int i=n-2; i>=1; i--) {
        sum += a[i];
        ans += sum;
    }
    
    cout<<ans<<"\n";
}