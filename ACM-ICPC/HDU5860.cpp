// Wrote by MenYifan on 2016-08-19 15:09:14
// Exe.Time 5444ms Exe.Memory 48552K
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
const int maxn=3000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int idx[maxn];
int rnd[maxn];
int sum[maxn];
int ans[maxn];
int main(){
    int T;
    int n,k,q;
    int tmp;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&k,&q);
        int maxRnd = 1;
        Memset(idx, 0);
        Memset(rnd, 0);
        Memset(sum, 0);
        Memset(ans, 0);
        
        rnd[0] = 1;
        idx[0] = 0;
        sum[1] = 1;
        
        for (int i=1; i<n; i++) {
            if (i % k == 0) {
                rnd[i] = 1;
                idx[i] = i;
                sum[rnd[i]]++;
            }
            else{
                tmp = i - i/k - 1;
                rnd[i] = rnd[tmp] + 1;
                idx[i] = idx[tmp];
                sum[rnd[i]]++;
                maxRnd = max(maxRnd, rnd[i]);
            }
        }
        
        for (int i=1; i<=maxRnd; i++) {
            sum[i] += sum[i-1];
        }
        
        for (int i=1; i<=n; i++) {
            ans[sum[rnd[i-1]-1] + idx[i-1] / k + 1] = i;
        }
        
        for (int i=0; i<q; i++) {
            scanf("%d",&tmp);
            cout<<ans[tmp]<<endl;
        }
    }
}