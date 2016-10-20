// Wrote by MenYifan on 2016-08-22 19:24:15
// Exe.Time 0ms Exe.Memory 1572K
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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

const int maxn=100000+5;
ll a[105],b[105];
int main(){//sb question
    int n,cas=1;
    while (scanf("%d",&n)!=EOF) {
        int vis[105]={};
        for (int i=1; i<=n; i++) {
            scanf("%lld",a+i);
            b[i] = a[i];
        }
        
        sort(a+1, a+1+n);
        sort(b+1, b+1+n);
        int cnt = unique(b+1, b+1+n) - b -1;
        if (cnt==1) {
            printf("Case #%d: %d\n",cas++,-1);
            continue;
        }
        int idx=1;
        for (int i=1; i<=n; i++) {
            if (a[i]==b[idx])
                vis[idx]++;
            else{
                vis[++idx]=1;
            }
        }

        b[0] = b[idx] ; b[idx+1] = b[1];
        int ans = 0;
        for (int i=1; i<=idx; i++) {
            if ((b[i]+b[i-1])%2147483647LL==b[i+1]) {
                ans+=vis[i];
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
}