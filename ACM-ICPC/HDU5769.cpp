// Wrote by MenYifan on 2016-07-31 10:28:07
// Exe.Time 140ms Exe.Memory 4768K
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
/* start ???? start */
char s[maxn],ch[2];
/*rk??????0?n-1
 sa,ht??????1?n
 ???????????*/

int rk[maxn], sa[maxn], ht[maxn], wa[maxn], wb[maxn], wx[maxn], wv[maxn];

bool isq(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];
}

bool isEqual(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];
}
// r???????0~n-1?m???????????+1)
void getSa(char r[], int n, int m) {
    int i, j, p, *t, *x = wa, *y = wb;
    for (i = 0; i < m; ++i)
        wx[i] = 0;
    for (i = 0; i < n; ++i)
        ++wx[x[i] = r[i]];
    for (i = 1; i < m; ++i)
        wx[i] += wx[i - 1];
    for (i = n - 1; i >= 0; --i)
        sa[--wx[x[i]]] = i;
    for (j = 1, p = 0; p < n; j <<= 1, m = p) {
        for (p = 0, i = n - j; i < n; ++i)
            y[p++] = i;
        for (i = 0; i < n; ++i)
            sa[i] >= j ? y[p++] = sa[i] - j : 0;
        for (i = 0; i < m; ++i)
            wx[i] = 0;
        for (i = 0; i < n; ++i)
            ++wx[wv[i] = x[y[i]]];
        for (i = 1; i < m; ++i)
            wx[i] += wx[i - 1];
        for (i = n - 1; i >= 0; --i)
            sa[--wx[wv[i]]] = y[i];
        p = 1, t = x, x = y, y = t;
        x[sa[0]] = 0;
        for (i = 1; i < n; ++i)
            x[sa[i]] = isEqual(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
    }
}

void getHet(char r[], int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; ++i)
        rk[sa[i]] = i;
    for (i = 0; i < n; ht[rk[i++]] = k) {
        k = k > 0 ? k - 1 : 0;
        j = sa[rk[i] - 1];
        while (r[i + k] == r[j + k])
            ++k;
    }
}
int nxt[maxn];
int main(){
    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        Memset(nxt, 0);
        scanf("%s",ch);
        scanf("%s",s);
        int len = (int)strlen(s);
        for (int i=0; i<len; i++) {
            nxt[i]=len;
            if (s[i]==ch[0]) {
                nxt[i]=i;
                int idx=i-1;
                while (idx>=0&&s[idx]!=ch[0]) {
                    nxt[idx--]=i;
                }
            }
        }
        getSa(s, len+1, 'z'+1);
        getHet(s, len);
        
        ll ans = 0;
        for (int i=1; i<=len; i++) {
            ans+=len-max(sa[i]+ht[i], nxt[sa[i]]);
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
}