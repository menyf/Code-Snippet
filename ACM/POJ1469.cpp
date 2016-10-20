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
#pragma comment(checker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=300+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int mp[maxn][maxn]={},flag[maxn]={},check[maxn];
int p,n;
int dfs(int u){
    for (int v=1; v<=p; v++)
        if (mp[u][v]&&!flag[v]) {
            flag[v]=1;
            if (check[v]==-1 ||dfs(check[v])) {
                check[v]=u;
                return 1;
            }
        }
    return 0;
}
int hungary(){
    memset(check,-1,sizeof(check));
    int rt=0;
    for (int u=1; u<=n; u++) {
        memset(flag,0,sizeof(flag));
        rt+=dfs(u);
    }
    return rt;
}
int main(){
    int t,tmp,pos;
    scanf("%d",&t);
    while (t--) {
        Memset(mp, 0);
        scanf("%d%d",&p,&n);
        for (int i=1; i<=p; i++) {
            scanf("%d",&tmp);
            for (int j=1; j<=tmp; j++) {
                scanf("%d",&pos);
                    mp[pos][i]=1;
            }
        }
        if (hungary()==p)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
