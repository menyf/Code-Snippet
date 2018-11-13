// Wrote by MenYifan on 2016-08-24 19:08:40
// Exe.Time 249ms Exe.Memory 1980K
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
int x[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n, k;
        scanf("%d%d",&n,&k);
        for (int i=1; i<=n; i++) {
            scanf("%d",x+i);
        }
        sort(x+1, x+1+n);
            
        ll ans = 0;
        int now = 1;
        for (int i=1; i<=n; i++) {
            while (now<=n&&x[now] - x[i] <= k) {
                now++;
            }
            ans += now - i - 1;
        }
        cout<<ans<<endl;
    }
}