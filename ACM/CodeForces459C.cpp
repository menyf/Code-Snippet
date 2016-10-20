// Wrote by MenYifan on 2016-09-03 14:34:52
// Exe.Time 218ms Exe.Memory 4020K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int ans[1005][1005];
int n,k,D,mx;
bool dfs(int l,int r,int k,int d){  //K??
    if (d > D) return false;

    if (r - l + 1 <= k) {
        for (int i=l,j=1; i<=r; i++,j++) {
            ans[d][i] = j ;
        }
        mx = max(mx, d);
        return true;
    }
    
    int up = ceil(1.0*(r-l+1)/k);
    int n = (r - l + 1) / up + ((r-l+1)%up ? 1:0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<up; j++) {
            int tmp = l + i * up + j ;
            if (tmp > r) break;
            ans[d][tmp] = i+1;
        }
    }
    
    for (int i=0; i<n; i++) {
        if (!dfs(l+i*up, min(l+(i+1)*up-1, r), k, d+1)) {
            return false;
        }
    }
    return true;
}
int main(){
    scanf("%d%d%d",&n,&k,&D);
    mx = 0;
    if (dfs(1, n, k, 1)) {
        for (int i=1; i<=mx; i++) {
            for (int j=1; j<=n; j++) {
                if (!ans[i][j]) {
                    ans[i][j] = 1;
                }
            }
        }
        for (int i=1; i<=mx; i++) {
            for (int j=1; j<=n; j++) {
                printf("%d",ans[i][j]);
                if (j!=n)
                    printf(" ");
                else
                    printf("\n");
            }
        }
        for (int i=mx+1; i<=D; i++) {
            for (int j=1; j<=n; j++) {
                printf("%d",ans[1][j]);
                if (j!=n)
                    printf(" ");
                else
                    printf("\n");
            }
        }
    }
    else
        puts("-1");
    
}