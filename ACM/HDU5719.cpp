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
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int b[maxn],c[maxn];
int t,n;
int main(){
    scanf("%d",&t);
    while (t--) {
        
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",b+i);
        }
        for (int i=1; i<=n; i++) {
            scanf("%d",c+i);
        }
        
        if (b[1]!=c[1]) {
            cout<<0<<endl;
            continue;
        }
        ll ans=1;
        for (int i=2,cnt=1; i<=n; i++) {
            if (b[i]==b[i-1]&&c[i]==c[i-1]) {
                ans*=(c[i]-b[i]+1-cnt)%mod;
                ans%=mod;
                cnt++;
            }
            else if (b[i]<b[i-1]&&c[i]==c[i-1]){
                cnt++;
            }
            else if (b[i]==b[i-1]&&c[i]>c[i-1]){
                cnt++;
            }
            else{
                ans=0;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
