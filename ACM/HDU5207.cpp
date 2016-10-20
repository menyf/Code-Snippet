// Wrote by MenYifan on 2016-09-16 19:15:16
// Exe.Time 1060ms Exe.Memory 1952K
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
const int maxn=100000+10;
int vis[maxn];
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        printf("Case #%d: ",cas++);
        int n;
        scanf("%d",&n);
        for (int i = 1; i<=n; i++) {
            int tmp;
            scanf("%d",&tmp);
            int sq = sqrt(tmp) + 0.5;
            for (int i = 1; i<=sq; i++) {
                if (tmp % i == 0) {
                    if (tmp / i == i) {
                        vis[i]++;
                    }
                    else{
                        vis[i]++,vis[tmp/i]++;
                    }
                }
            }
        }
        for (int i = 1e5; i>=1; i--) {
            if (vis[i] >= 2) {
                printf("%d\n",i);
                break;
            }
        }
    }
}