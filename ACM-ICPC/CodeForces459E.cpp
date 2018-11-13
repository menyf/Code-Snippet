// Wrote by MenYifan on 2016-09-03 21:01:01
// Exe.Time 187ms Exe.Memory 5876K
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
const int maxn=300000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Edge{
    int u,v,w;
    void in(){
        scanf("%d%d%d",&u,&v,&w);
    }
    bool operator < (const Edge &e) const{
        return w < e.w;
    }
}e[maxn];
int v[maxn],dp[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++) {
        e[i].in();
    }
    sort(e+1, e+1+m);
    int id = 1;
    for (int i=1; i<=m; i++) {
        while (e[id].w < e[i].w) {
            v[e[id].v] = max(v[e[id].v], dp[id]);
            id++;
        }
        dp[i] = v[e[i].u] + 1;
    }
    int ans = 0;
    for (int i=1; i<=m; i++) {
        ans = max(dp[i], ans);
    }
    cout<<ans<<'\n';
}