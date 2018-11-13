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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[maxn],L,R;
int t,n;
struct Segment{
    ll l,r;
    Segment(){
        l=r=0;
    }
    bool operator<(Segment x)const{
        return l!=x.l?(l<x.l):(r<x.r);
    }
}seg[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%lld%lld",&n,&L,&R);
        for (int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        sort(a, a+n);
        int cnt=1;
        for (int i=1; i<n; i++) {
            seg[cnt].l = a[i]-a[i-1]+1;
            seg[cnt].r = a[i]+a[i-1]-1;
            if (seg[cnt].l>R||seg[cnt].r<L)
                continue;
            seg[cnt].l=max(seg[cnt].l, L);
            seg[cnt].r=min(seg[cnt].r, R);
            cnt++;
        }
        
        sort(seg+1, seg+cnt);
        
        ll ans = R-L+1,right=-1;
        for (int i=1; i<cnt; i++) {
            if (seg[i].l>right){
                ans -= seg[i].r-seg[i].l+1;
            }
            else if (seg[i].r>right){
                ans -= seg[i].r-right;
            }
            right=max(right, seg[i].r);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
 3
 2 2 2
 3 3
 ANS:0
 
 2 2 2
 1 3
 ANS:1
*/
