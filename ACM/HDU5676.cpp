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
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[2000200];
int cnt=0;
void dfs(ll val,int x,int y) {
    if (x==y) {
        a[cnt++]=val;
    }
    if (x+y==18) {
        return;
    }
    dfs(10*val+4, x+1, y);
    dfs(10*val+7, x, y+1);
}
int main(){
    dfs(0, 0, 0);
    sort(a, a+cnt);
//    for (int i=0; i<cnt; i++) {
//        cout<<i<<"--"<<a[i]<<endl;
//    }
    int t;
    ll n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld",&n);
        if (n>777777777444444444LL) {
            printf("44444444447777777777\n");
            continue;
        }

//        int l = 0, r = cnt;
//        while (l + 1 < r) {
//            //                    cout << l << ' ' << r << endl;
//            int m = l + r >> 1;
//            if (a[m] > n) r = m;
//            else l = m;
//        }
        
        int r = lower_bound(a+1, a+cnt, n)-a;
        //            cout << a[r] << endl;
        printf ("%lld\n", a[r]);
    }
}
