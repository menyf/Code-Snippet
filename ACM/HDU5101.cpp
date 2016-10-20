// Wrote by MenYifan on 2016-08-01 11:31:03
// Exe.Time 639ms Exe.Memory 2388K
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
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+50;
ll a[maxn];
int main(){
    int T,n,iq,m,tmp;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&iq);
        ll tmp=0;
        int cnt=0;
        for (int i=0; i<n; i++) {
            scanf("%d",&m);
            int st = cnt,ed = cnt+m;
//            debug2(st, ed);
            for (int j=0; j<m; j++) {
                scanf("%lld",&a[cnt++]);
            }
            sort(a+st, a+ed);
            int l = st,r=ed-1;
//            debug2(l, r);
            while (l<r) {
                if (a[r]+a[l]>iq) {

                    tmp+=r-l;
//                    debug2(r, l);
//                    hi;
                r--;
//                    debug(tmp);
                }
                else{
                    l++;
                }
            }
        }
//        for (int i=0; i<cnt; i++) {
//            printf("%lld ",a[i]);
//        }
        ll total=0;
        int l=0,r=cnt-1;
        sort(a, a+cnt);
        while (l<r) {
            if (a[r]+a[l]>iq) {
                total+=r-l;
                r--;
            }
            else
                l++;
        }
//        debug(total);
        cout<<total-tmp<<endl;
    }
    return 0;
}