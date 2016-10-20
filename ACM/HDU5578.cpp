// Wrote by MenYifan on 2016-09-13 18:16:46
// Exe.Time 0ms Exe.Memory 1568K
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
char str[1005];
int vis[26];
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",str);
        int ans = INF;
        memset(vis, -1, sizeof(vis));
        for (int i = 0; str[i]; i++) {
            int now = str[i] - 'a';
            if (vis[now] != -1) {
                ans = min(ans, i - vis[now]);
            }
            vis[now] = i;
        }
        printf("Case #%d: %d\n",cas++,ans==INF?-1:ans);
    }
}