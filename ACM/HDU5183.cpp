// Wrote by MenYifan on 2016-08-26 21:27:23
// Exe.Time 1248ms Exe.Memory 56536K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a;
ll sum[maxn];
set<ll>st;
int main(){
#ifdef ONLINE_JUDGE
#else
    // freopen("in.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    double t1 = clock();
#endif
    int n,T,cas=1,k;
    scanf("%d",&T);
    while (T--) {
        bool flag =false;
        scanf("%d%d",&n,&k);
        st.clear();
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a);
            sum[i] = sum[i-1] + ((i&1)?a:-a);
        }
        
        for (int i=n; i>=1; i--) {
            st.insert(sum[i]);
            
            if (i&1) {
                if (st.find(sum[i-1]+k)!=st.end()) {
                    flag = true;
                    break;
                }
            }
            else{
                if(st.find(sum[i-1]-k)!=st.end()){
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag) {
            printf("Case #%d: Yes.\n",cas++);
        }
        else{
            printf("Case #%d: No.\n",cas++);
        }
        
    }
    
    
#ifdef ONLINE_JUDGE
#else
    printf("\n----\nFinished, time used: ");
    cerr << (clock()-t1) / CLOCKS_PER_SEC ;
    printf("s\n");
#endif
    return 0;
}