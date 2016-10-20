// Wrote by MenYifan on 2016-09-02 11:31:05
// Exe.Time 764ms Exe.Memory 1692K
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
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int MAXNODE = 100005;
const int MAXM = 105;
const int MAXN = 105;
struct DancingLinksX
{
    int n,m,sz,K;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE],Row[MAXNODE],Col[MAXNODE];
    int H[MAXN],S[MAXM];
    int ands,ans[MAXN];
    
    void init(int _n,int _m,int _K)
    {
        n = _n;
        m = _m;
        K=_K;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        sz = m;
        for(int i = 1 ; i <= n ; i++)
            H[i] = -1;
    }
    
    void Link(int r,int c)
    {
        ++S[Col[++sz] = c];
        Row[sz] = r;
        D[sz] = D[c];
        U[D[c]] = sz;
        U[sz] = c;
        D[c] = sz;
        if(H[r] < 0)H[r] = L[sz] = R[sz] = sz;
        else
        {
            R[sz] = R[H[r]];
            L[R[H[r]]] = sz;
            L[sz] = H[r];
            R[H[r]] = sz;
        }
    }
    
    void Remove(int c)
    {
        for(int i = D[c] ; i != c ; i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    
    void resume(int c)
    {
        for(int i = U[c] ; i != c ; i = U[i])
            L[R[i]] = R[L[i]] = i;
    }
    
    bool v[MAXNODE];
    int f()
    {
        int ret = 0;
        for(int c = R[0] ; c != 0 ; c = R[c])v[c] = true;
        for(int c = R[0] ; c != 0 ; c = R[c])
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c] ;i != c ;i = D[i])
                    for(int j = R[i] ;j != i ; j = R[j])
                        v[Col[j]] = false;
            }
        return ret;
    }
    
    bool Dance(int d=0)
    {
        if(d + f() > K)return false;
        if(R[0] == 0)return d <= K;
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            Remove(i);
            for(int j = R[i] ; j != i ; j = R[j])Remove(j);
            if(Dance(d + 1))return true;
            for(int j = L[i] ; j != i ; j = L[j])resume(j);
            resume(i);
        }
        return false;
    }
}DLX;
struct Point{
    ll x,y;
}p[MAXN];
ll dis(Point &a, Point b){
    return abs(a.x - b.x)+abs(a.y - b.y);
}
int main()
{
    int T;
    int n,k;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        scanf("%d%d",&n,&k);
        for (int i=1; i<=n; i++) {
            scanf("%lld%lld",&p[i].x,&p[i].y);
        }
        ll l = 0, r = 100000000000LL,ans=0;
        while (l < r) {
            ll mid = (l + r)>>1;
            DLX.init(n, n, k);
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (dis(p[i], p[j])<=mid) {
                        DLX.Link(i, j);
                    }
                }
            }
            if (DLX.Dance()) {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        printf("Case #%d: %lld\n",cas++,l);
    }
    return 0;
}