#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define pii pair<int,int>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Point{
    int x,y;
}p[15];
int vis[15],cnt,dp[1<<12][15];
bool cmp(Point a,Point b){
    if (a.x==b.x) {
        return a.y<b.y;
    }
    else
        return a.x<b.x;
}
int main(){
    int n,m,tmp;
    while (scanf("%d%d",&n,&m)!=EOF) {
        cnt=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                scanf("%d",&tmp);
                if (tmp!=0) {
                    p[cnt].x=i-1;
                    p[cnt++].y=j-1;
                }
            }
        }
        
        int ans=INF;
        do{
            tmp = p[0].x + p[0].y;
            for (int i=1; i<cnt; i++) {
                tmp+= abs(p[i].x-p[i-1].x)+abs(p[i].y-p[i-1].y);
            }
            tmp += p[cnt-1].x + p[cnt-1].y;
            ans = min(ans, tmp);
            
        }while (next_permutation(p, p+cnt, cmp)) ;
    
        cout<<ans<<endl;
    }
}
