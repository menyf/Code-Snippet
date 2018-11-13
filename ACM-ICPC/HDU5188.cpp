// Wrote by MenYifan on 2016-09-02 22:26:25
// Exe.Time 140ms Exe.Memory 13324K
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
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int n,w;
struct node{
    int t,v,l;
    void in(){
        scanf("%d%d%d",&t,&v,&l);
    }
    bool operator < (const node &x)const{
        return l-t < x.l-x.t;
    }
}p[35];
int dp[3000010];
int main(){
    while (scanf("%d%d",&n,&w)!=EOF) {
        int sumV = 0, mx = 0, sumT = 0, mxL = 0;
        for (int i=1; i<=n; i++) {
            p[i].in();
            sumV += p[i].v;
            sumT += p[i].t;
            mxL = max(mxL, p[i].l);
        }

        mx = max(sumT, mxL);
        if (sumV < w) {
            printf("zhx is naive!\n");
            continue ;
        }
        sort(p+1, p+1+n);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i=1; i<=n; i++) {
            for (int j = mx; j>=p[i].l&&j>=p[i].t; j--) {
                dp[j] = max(dp[j], dp[j-p[i].t] + p[i].v);
            }
        }
        for (int i=0; i<=mx; i++) {
            if (dp[i]>=w) {
                ans = i;
                break;
            }
        }
        if (ans) {
            printf("%d\n",ans);
        }
        else{
            printf("zhx is naive!\n");
        }
    }
}