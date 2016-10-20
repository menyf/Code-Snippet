// Wrote by MenYifan on 2016-09-06 14:05:25
// Exe.Time 375ms Exe.Memory 0K
//HDU 3849
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
const int maxn=1e6+10;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll add[maxn<<2],sum[maxn<<2];
void PushUp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if (add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * (m - (m >> 1));
        sum[rt<<1|1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void build(int l,int r,int rt=1)
{
    add[rt] = 0;
    if (l == r)
    {
        sum[rt]=0;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,ll c,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        add[rt] += c;
        sum[rt] += c * (r - l + 1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (m < R) update(L , R , c , rson);
    PushUp(rt);
}
ll query(int L,int R,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L , R , lson);
    if (m < R) ret += query(L , R , rson);
    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int R,n,L,T,W,H;
        scanf("%d%d",&R,&n);
        build(1, R);
        ll tot = 0;
        for (int i=0; i<n; i++) {
            scanf("%d%d%d%d",&L,&T,&W,&H);
            if (L + 1 > R ) {
                continue;
            }
            update(min(L+1, R), min(L+W, R), min(H, T), 1, R);
            tot += (ll)min(H, T) * min(W, R-L);
        }
        
        int l = 1, r = R;
        while ( l < r - 1) {
            int mid = (l + r) / 2;
            if (query(1, mid, 1, R) <= query(mid + 1, R, 1, R)) {
                l = mid;
            }
            else{
                r = mid;
            }
        }
//        debug2(l, r);
        int ans = 0;
        if (query(1, l, 1, R) >= query(l+1, R, 1, R)) {
            l++;
            while (l<=R && query(l, l, 1, R) == 0 || query(1, l, 1, R) <= (tot+1)/2) {
                l++;
            }
            if (l == R) {
                ans = R;
            }
            else
                ans = l - 1;
        }
        else{
            r++;
            while (r<=R && query(r, r, 1, R) == 0 || query(1, r, 1, R) <= (tot+1)/2) {
                r++;
            }
            if (r == R) {
                ans = R;
            }
            else
                ans = r - 1;
        }
        
        cout<<ans<<"\n";
    }
}