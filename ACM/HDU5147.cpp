// Wrote by MenYifan on 2016-08-10 19:28:44
// Exe.Time 1154ms Exe.Memory 2960K
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
const int maxn=50000+5;
const double eps=1e-8;
int n,a[maxn];
ll x[maxn],y[maxn],bin[maxn];
int lowbit(int x){
    return x&(-x);
}
void update(int pos,ll val){
    while (pos<=n) {
        bin[pos]+=val;
        pos+=lowbit(pos);
    }
}
ll sum(int pos){
    ll ans=0;
    while (pos>0) {
        ans+= bin[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        Memset(x, 0);
        Memset(y, 0);
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        Memset(bin, 0);
        for (int i=1; i<=n; i++) {
            update(a[i], 1);
            x[i] = sum(a[i])-1;
        }
        Memset(bin, 0);
        for (int i=n,j=1; i>=1; i--,j++) {
            update(a[i], 1);
            y[i] = j - sum(a[i]);
            y[i] += y[i+1];
        }
        ll ans = 0;
        for (int i=1; i<=n; i++) {
            ans += x[i] * y [i+1];
        }
        cout<<ans<<endl;
    }
}