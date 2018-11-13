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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[100000+10],vis[maxn];
int main(){
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        int sum=0;
        bool flag=false;
        Memset(vis, 0);
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            sum+=a[i];
            int tmp = sum%m;
            if (vis[tmp]||tmp==0) {
                flag=true;
            }
            else
                vis[tmp]=1;
        }
     
        
        if (flag) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
