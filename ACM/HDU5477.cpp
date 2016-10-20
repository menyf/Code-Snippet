// Wrote by MenYifan on 2016-08-23 12:40:07
// Exe.Time 0ms Exe.Memory 1576K
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
struct seg{
    int x,y,cost;
    bool operator < (const seg &a)const{
        return x<a.x;
    }
}s[maxn];
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        int n,len,a,b;
        int ans = 0;

        scanf("%d%d%d%d",&n,&a,&b,&len);
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&s[i].x,&s[i].y);
            if (s[i].x>s[i].y) {
                swap(s[i].x, s[i].y);
            }
            s[i].cost = (s[i].y - s[i].x) * a;
        }

        sort(s+1, s+1+n);
        int now = 0;
        for (int i=1; i<=n; i++) {
            now += (s[i].x - s[i-1].y) * b;
            if (now<s[i].cost) {
                ans += s[i].cost - now;
                now = 0;
            }
            else
                now -= s[i].cost;
        }
        
        printf("Case #%d: %d\n",cas++,ans);
        
    }
    return 0;
}
