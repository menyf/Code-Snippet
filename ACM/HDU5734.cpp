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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define mp make_pair
#define pb push_back
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        ll n;
        scanf("%lld",&n);
        ll one=0,two=0;
        for (int i=0; i<n; i++) {
            scanf("%lld",&a[i]);
            one+=fabs(a[i]);
            two+=a[i]*a[i];
        }
        ll up=0,down=n,fenzi=one,fenmu=n;
        if (fenzi!=0) {
            ll gcd = __gcd(fenzi,fenmu);
            fenzi/=gcd;
            fenmu/=gcd;
        }
        
        ll gcd = __gcd(fenmu,n);
        
        up = fenmu*fenmu/gcd*two -2*fenmu/gcd*one*fenzi+n/gcd*fenzi*fenzi;
        down = fenmu * fenmu/gcd;//0
       
        if (up==0) {
            cout<<"0/1"<<endl;
        }
        else{
            ll gcd = __gcd(up,down);
            cout<<up/gcd<<"/"<<down/gcd<<endl;
        }
    }
}

