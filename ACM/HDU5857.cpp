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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[maxn];
ll fuck(int l1,int r1, int l2,int r2,int idx){
    int len1 = r1 - l1 + 1;
    int len2 = r2 - l2 + 1;
    int pre = r1 - l1 + 1 + r1 - l2 + 1;
    if (l1 + idx - 1 <= l2) {
        return a[l1 + idx - 1];
    }
    else if (pre < idx){
        return a[r1 + idx - pre];
    }
    else{
        idx -= l2 - l1;
        idx --;
        idx /= 2;
        return a[l2 + idx];
    }
}
int main(){
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            scanf("%lld",a+i);
        }
        int l1,l2,r1,r2;
        double ans;
        for (int cas = 1; cas <= m; cas++) {
            ans = 0;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if (r1<=l2||r2<=l1) {
                if (r2<=l1) {
                    swap(l1, l2);
                    swap(r1, r2);
                }
                int len1 = r1 - l1 + 1;
                int len2 = r2 - l2 + 1;
                int tot = len1 + len2 ;
                if (tot % 2 == 0) {
                    tot /= 2;
                    if (tot<=len1) {
                        ans = a[l1 + tot - 1];
                        if (tot+1<=len1) {
                            ans += a[l1 + tot];
                        }
                        else{
                            tot= 1 + tot - len1;
                            ans += a[l2 + tot -1];
                        }
                    }
                    else{
                        tot -= len1;
                        ans = a[l2 + tot -1];
                        ans += a[l2 + tot];
                    }
                    ans /= 2;
                }
                else{
                    tot = tot / 2 + 1;
                    if (tot <= len1) {
                        ans = a[l1 + tot - 1];
                    }
                    else{
                        tot -= len1;
                        ans = a[l2 + tot - 1];
                    }
                }
            }
            else {
                /*l1 < l2 < r1 < r2*/
                int num[5];
                num[0] = l1;
                num[1] = l2;
                num[2] = r1;
                num[3] = r2;
                sort(num, num+4);
                l1 = num[0]; r1 = num[2];
                l2 = num[1]; r2 = num[3];

                int len1 = r1 - l1 + 1;
                int len2 = r2 - l2 + 1;
                int tot = len1 + len2;
                if (tot % 2) {
                    int idx = tot / 2 + 1;
                    ans = fuck(l1, r1, l2, r2, idx);
                }
                else{
                    int idx = tot / 2;
                    ans = fuck(l1, r1, l2, r2, idx) + fuck(l1, r1, l2, r2, idx + 1);
                    ans /= 2;
                }
            }
            printf("%.1f\n",ans);
        }
    }
}
