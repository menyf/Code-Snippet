// Wrote by MenYifan on 2016-08-05 16:07:31
// Exe.Time 250ms Exe.Memory 0K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
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
const int mod=110119;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll dp[1005][1005][2];
int n,v,x,st;
ll pred[1005];
struct node{
    int x;
    int c,d;
    bool operator < (const node &a) const{
        return x<a.x;
    }
}p[1100];
int main(){
    while (~scanf("%d%d%d",&n,&v,&x)&&n) {
        p[n+1].x= x; p[n+1].c=p[n+1].d=0;
        for (int i=1; i<=n; i++)
            scanf("%d%d%d",&p[i].x,&p[i].c,&p[i].d);
        sort(p+1, p+n+2);
        st = 0;
        ll sum = 0;
        for (int i=1; i<=n+1; i++) {
            if (p[i].x==x) st = i;
            pred[i] = p[i].d + pred[i-1];
            sum += p[i].c;
        }
        Memset(dp, 0x3f);
        dp[st][st][0]=dp[st][st][1]=0;
        for (int i = st; i>=1; i--) {
            for (int j = st; j<= n+1; j++) {
                ll tmp = pred[i-1] + pred[n+1] -pred[j];
                if (i-1>=1) {
                    dp[i-1][j][0] = min(dp[i-1][j][0], dp[i][j][0]+(p[i].x-p[i-1].x)*tmp);
                    dp[i-1][j][0] = min(dp[i-1][j][0], dp[i][j][1]+(p[j].x-p[i-1].x)*tmp);
                }
                if (j+1<=n+1) {
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][0]+(p[j+1].x-p[i].x)*tmp);
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][1]+(p[j+1].x-p[j].x)*tmp);
                }
            }
        }
        
        printf("%lld\n",min(dp[1][n+1][0],dp[1][n+1][1])/v + sum);
    }
    return 0;
}