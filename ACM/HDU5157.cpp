// Wrote by MenYifan on 2016-08-13 23:02:45
// Exe.Time 62ms Exe.Memory 15376K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int MAXN = 100005 ;
const int N = 26 ;

struct Palindromic_Tree {
    int next[MAXN][N] ;//next???next????????????????????????????
    int fail[MAXN] ;//fail?????????fail???????
    int cnt[MAXN] ;
    int num[MAXN] ;
    int len[MAXN] ;//len[i]????i?????????
    int S[MAXN] ;//???????
    int last ;//??????????????????add
    int n ;//??????
    int p ;//????
    
    int newnode ( int l ) {//????
        for ( int i = 0 ; i < N ; ++ i ) next[p][i] = 0 ;
        cnt[p] = 0 ;
        num[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }
    
    void init () {//???
        p = 0 ;
        newnode (  0 ) ;
        newnode ( -1 ) ;
        last = 0 ;
        n = 0 ;
        S[n] = -1 ;//???????????????????
        fail[0] = 1 ;
    }
    
    int get_fail ( int x ) {//?KMP??????????????
        while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;
        return x ;
    }
    
    int add ( int c ) {
        c -= 'a' ;
        S[++ n] = c ;
        int cur = get_fail ( last ) ;//???????????????????
        if ( !next[cur][c] ) {//??????????????????????????????
            int now = newnode ( len[cur] + 2 ) ;//????
            fail[now] = next[get_fail ( fail[cur] )][c] ;//?AC???????fail??????????
            next[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
        }
        last = next[cur][c] ;
        cnt[last] ++ ;
        return num[last];
    }
    
    void count () {
        for ( int i = p - 1 ; i >= 0 ; -- i ) cnt[fail[i]] += cnt[i] ;
        //???????cnt?????fail[v]=u??u???v??????
    }
}p;
char s[maxn];
ll l[maxn],r[maxn];
int main(){
    while (~scanf("%s",s+1)) {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        int len = strlen(s+1);
        p.init();
        for (int i=1; i<=len; i++) {
            l[i] = l[i-1] + p.add(s[i]);
        }
        p.init();
        ll ans = 0;
        for (int i=len; i>=1; i--) {
            ans += l[i-1] * p.add(s[i]);
        }
        cout<<ans<<endl;
        
    }
}