// Wrote by MenYifan on 2016-09-15 20:58:16
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
const int maxn=50000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int calc(int len1,int len2){
    if ((len1+len2)%2==0) {
        int tmp1 = (len1 + len2) / 2;
        int tmp2 = len2 - tmp1;
        return max(0, tmp1 - tmp2 - 1);
    }
    else
        return len1;
}
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int mx=-1,mn = INF;
        for (int i = 0; i<m; i++) {
            int tmp;
            scanf("%d",&tmp);
            mx = max(mx, tmp);
            mn = min(mn, tmp);
       }
        int len1 = mn - 1;
        int len2 = n - mx;
        
        ll ans = 0;
        if (len1 == 0 && len2 != 0) {
            for (int i = 1; i < len2 - i; i++)
                ans += calc(i, len2 - i);
        }
        else if (len2 == 0 && len1 != 0) {
            for (int i = 1; i < len1 - i; i++)
                ans += calc(i, len1 - i);
        }
        else if (len1 != 0 && len2 != 0) {
            if (len1 > len2) swap(len1, len2);
            ans = calc(len1,len2);
        }
        
        printf("%lld\n",ans);
    }
}