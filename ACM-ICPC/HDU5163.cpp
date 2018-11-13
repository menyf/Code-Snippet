// Wrote by MenYifan on 2016-08-17 19:39:52
// Exe.Time 1341ms Exe.Memory 2364K

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
ll dis[maxn];
int main(){
    int T,n,m,st,up,down;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1; i<n; i++) {
            scanf("%lld",dis+i);
            dis[i] += dis[i-1];
        }
        for (int i=1; i<=m; i++) {
            ll ans = 0;
            st = (i-1)%n+1;
            scanf("%d%d",&up,&down);
            if (up>=st) {
                ans += dis[up-1] - dis[st-1];
                if (down >= up) {
                    ans += dis[down-1] - dis[up-1];
                }
                else{
                    ans += dis[up-1] - dis[down - 1];
                    ans += 2 * (dis[n-1] - dis[up-1]);
                }
            }
            else{
                ans += 2 * (dis[n-1] - dis[st - 1]);
                ans += dis[st-1] - dis[up - 1];
                if (down <= up) {
                    ans += dis[up-1] - dis[down -1];
                }
                else{
                    ans += 2 * dis[up - 1];
                    ans += dis[down-1] - dis[up - 1];
                }
            }
            cout<<ans<<endl;
        }
    }
}