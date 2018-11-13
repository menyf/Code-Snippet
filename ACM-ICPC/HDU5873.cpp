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
const int maxn=100001+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn];
int vis[maxn];
int main(){
    int T;
    while (scanf("%d",&T)!=EOF) {
        ll n;
        while (T--) {
            memset(vis, 0, sizeof(vis));
            scanf("%lld",&n);
            ll sum = 0,tot=0;
            sum = n * (n-1);
            bool flag = true;
            for (int i=1; i<=n; i++) {
                if (!flag) {
                    scanf("%*d");
                    continue;
                }
                scanf("%d",&a[i]);
                if (a[i] > 2*(n-1)) flag = false;
                vis[a[i]]++;
                tot += a[i];
            }
            if (tot != sum ){
                flag = false;
            }
            for (int i = 0; i<2*(n-1)&&flag; i++) {
                if (vis[i] > i +1) {
                    flag = false;
                }
            }
            
            if (flag) puts("T");
            else puts("F");
        }
        
    }
   
}
