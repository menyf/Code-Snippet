// Wrote by MenYifan on 2016-04-03 21:26:24
// Exe.Time 436ms Exe.Memory 4120K
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
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[maxn];
void work(){
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
    }
    if (n==1||n==2) {
        printf("%d\n",n);
        return;
    }
    int ans=2,id=1;
    while (id!=n-1) {
        int mx=2;
        ll aa=a[id],bb=a[id+1],cc=a[id+2];
        if (aa+cc==bb*2) {
            while (aa+cc==bb*2) {
                mx++;
                id++;
                if (id==n-1)
                    break;
                aa=a[id],bb=a[id+1],cc=a[id+2];
            }
            ans=max(ans, mx);
        }
        else if (aa*cc==bb*bb){
            while (aa*cc==bb*bb) {
                mx++;
                id++;
                if (id==n-1)
                    break;
                aa=a[id],bb=a[id+1],cc=a[id+2];
            }
            ans=max(ans, mx);
        }
        else
            id++;
    }
    printf("%d\n",ans);
    return;
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        work();
    }
}