// Wrote by MenYifan on 2016-09-09 20:46:33
// Exe.Time 639ms Exe.Memory 2752K
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
const double eps=1e-11;
const int maxn=150000+10;
ll a[maxn];
int main(){
    int n;
    ll w,h;
    while (scanf("%d%lld%lld",&n,&w,&h)!=EOF) {
        memset(a, 0, sizeof(a));
        ll sum = 0;
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[w+i]);
            sum += a[w+i];
        }
        if (sum < w * h) {
            printf("-1\n");
            continue;
        }
        // tot1 ?????????
        // tot2 ?????????
        ll tot1=0,tot2=w*h,ans = w*h;
        for (ll l = 2, r = l+w-1; l<=w+n; l++,r++) {
            if (a[l-1] < h) {
                tot2 -= h-a[l-1];
            }
            else{
                tot1 -= a[l-1] - h;
            }
            if (a[r] > h) {
                tot1 += a[r] - h;
            }
            else{
                tot2 += h - a[r];
            }
            ans = min(ans, min(tot1, tot2) + abs(tot2 - tot1));
        }
        cout<<ans<<"\n";
    }
}