#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define pb push_back
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int x[maxn],y[maxn],vis[maxn*2];
int main(){
    int t, n, m ;
    scanf("%d",&t);
    while (t--) {
        bool flag=false;
        Memset(vis, 0);
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
            scanf("%d%d",x+i,y+i);
        for (int i=1; i<=n&&!flag; i++) {
            for (int j=i+1; j<=n&&!flag; j++) {
                int tmp = abs(x[i]-x[j])+abs(y[i]-y[j]);
                if (++vis[tmp]==2) flag=true;
            }
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
