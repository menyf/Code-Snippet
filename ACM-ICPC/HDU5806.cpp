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
const int maxn=200000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            if (a[i]>=m) a[i]=1;
            else a[i]=0;
            a[i] += a[i-1];
        }
        ll ans= 0;
        for (int i=0; i<=n-k; i++) {
            int pos = lower_bound(a+1, a+1+n, a[i]+k) - a;
            ans += n - pos + 1;
        }
        cout<<ans<<endl;
    }
}
