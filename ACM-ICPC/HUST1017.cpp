// Wrote by MenYifan on 2016-09-03 21:30:28
// Exe.Time 236ms Exe.Memory 1928K
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
const int MAXN = 1010;
const int MAXM = 1010;
const int MAXNODE = MAXN * MAXN;
int g[MAXN];
struct DLX
{
    int n,m,sz;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE],Row[MAXNODE],Col[MAXNODE];
    int H[MAXN],S[MAXM];
    int ansd,ans[MAXN];
    
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0 ; i <= m ; i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m;
        sz = m;
        for(int i = 1 ; i <= n ; i++) H[i] = -1;
    }
    
    void link(int r,int c)
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
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c] ; i != c ; i = D[i])
            for(int j = R[i] ; j != i ; j = R[j])
            {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }
    
    void resume(int c)
    {
        for(int i = U[c] ; i != c ; i = U[i])
            for(int j = L[i] ; j != i ; j = L[j])
                ++S[Col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }
    
    bool Dance(int d)
    {
        if(R[0] == 0)
        {
            printf("%d ",d);
            for (int i = 0 ; i < d ; i++)
                printf("%d%c",ans[i],i == d - 1 ? '\n' : ' ');
            return true;
        }
        int c = R[0];
        for(int i = R[0] ; i != 0 ; i = R[i])
            if(S[i] < S[c])
                c = i;
        Remove(c);
        for(int i = D[c] ; i != c ; i = D[i])
        {
            ans[d] = Row[i];
            for(int j = R[i] ; j != i ; j = R[j]) Remove(Col[j]);
            if(Dance(d + 1))return true;
            for(int j = L[i] ; j != i ; j = L[j]) resume(Col[j]);
        }
        resume(c);
        return false;
    }
}dlx;
int main(){
    int n,m,k,tmp;
    while (scanf("%d%d",&n,&m)!=EOF) {
        dlx.init(n, m);
        for (int i=1; i<=n; i++) {
            scanf("%d",&k);
            for (int j=1; j<=k; j++) {
                scanf("%d",&tmp);
                dlx.link(i, tmp);
            }
        }
        if (!dlx.Dance(0))
            puts("NO");
        putchar('\n');
    }
    return 0;
}