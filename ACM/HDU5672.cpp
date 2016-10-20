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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char s[1000005];
int vis[130];
int main(){
    int t,n;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++) {
        Memset(vis, 0);
        scanf("%s",s+1);
        scanf("%d",&n);
        int l=1,r=1,len=strlen(s+1),cnt=0;
        bool flag=false;
        ll ans=0;
        while (1) {
            while (cnt!=n) {
                if (r==len+1) {
                    flag=true;
                    break;
                }
                if (vis[s[r]]++==0) {
                    cnt++;
                }
                r++;
            }
            if (flag) {
                break;
            }
            ans+=len-(r-1)+1;
            if (--vis[s[l]]==0) {
                cnt--;
            }
            l++;
        }
        printf("%lld\n",ans);
    }
}

