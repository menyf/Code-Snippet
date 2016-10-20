// Wrote by MenYifan on 2016-09-13 19:04:09
// Exe.Time 62ms Exe.Memory 3260K
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
char str[maxn];
ll l[maxn],r[maxn];
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        printf("Case #%d: ",cas++);
        scanf("%s",str+1);
        int len = strlen(str+1);
        if (len == 1) {
            printf("1\n");
            continue;
        }
        l[1] = 1;
        int left = 1;
        ll tot = 0;
        for (int i = 2; i<=len; i++) {
            if (str[i] == str[i-1]) {
                l[i] = l[i-1];
            }
            else{
                for (int j = i-1; j>=left; j--) {
                    r[j] = i-1;
                }
                l[i] = i;
                left = i;
            }
        }
        for (int i = len; i >= left; i--) {
            r[i] = len;
        }
        
        for (int i = 1; i<=len; i++) {
            if (l[i]!=l[i-1]) {
                tot += (r[i] - l[i] + 1)*(r[i] - l[i] + 1);
            }
        }
        
        ll mx = 0;
        for (int i = 2; i<len; i++) {
            if (str[i]!=str[i-1]) {
                if (l[i] == r[i]) {//??
                    ll tmp1 = 1 + (r[i-1] - l[i-1] + 1) * (r[i-1] - l[i-1] + 1) + (r[i+1] - l[i+1] + 1) * (r[i+1] - l[i+1] + 1);
                    ll tmp2 = (r[i+1] - l[i-1] + 1)*(r[i+1] - l[i-1] + 1);
                    mx = max(mx, tmp2 - tmp1);
                }
                else{
                    ll tmp1 = (r[i-1] - l[i-1] + 1)*(r[i-1] - l[i-1] + 1) + (r[i]-l[i]+1)*(r[i]-l[i]+1);
                    ll tmp2 = (r[i-1] - l[i-1] + 2)*(r[i-1] - l[i-1] + 2) + (r[i]-l[i])*(r[i]-l[i]);
                    mx = max(mx, tmp2 - tmp1);
                }
            }
        }
        
        if (l[1] == r[1]) {
            ll tmp1 = 1 + (r[2]-l[2]+1)*(r[2]-l[2]+1);
            ll tmp2 =(r[2]-l[2]+2)*(r[2]-l[2]+2);
            mx = max(mx, tmp2-tmp1);
        }
        
        if (l[len]==r[len]) {
            ll tmp1 = 1 + (r[len-1] - l[len-1] + 1 )*(r[len-1] - l[len-1] + 1 );
            ll tmp2 =(r[len-1] - l[len-1] + 2)*(r[len-1] - l[len-1] + 2);
            mx = max(mx, tmp2 - tmp1);
        }
        cout<<tot+mx<<"\n";
    }
}