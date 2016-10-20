#include <set>
#include <map>
#include <list>
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
#define fre() freopen("data_in.txt","r",stdin); \
              freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
ll a[10]={1},b[10]={1};
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i = 1 ; i <= n ; i++) 
            scanf("%lld",&a[i]);
        for (int i = 1 ; i <= n ; i++) 
            scanf("%lld",&b[i]);
        ll fz = b[n], fm = a[n];
        for (int i = n - 1 ; i >= 1 ; i--) {
            fz = fm * a[i] + fz;
            fm = fm;
            swap(fz, fm);
            fz *= b[i];
            ll gcd = __gcd(fz, fm);
            fz /= gcd;
            fm /= gcd;
        }
        ll gcd = __gcd(fz, fm);
        fz /= gcd;
        fm /= gcd;
        printf("Case #%d: %lld %lld\n",cas++, fz,fm);
    }    
}
