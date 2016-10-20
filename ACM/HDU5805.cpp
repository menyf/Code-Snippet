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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct node{
    int val,l,r;
}p[maxn];
const int NVB = 33;
int mx[maxn][NVB],mn[maxn][NVB];
void init(int data[],int n){
    /*data下标从1开始*/
    int k = log2(n);
    for(int i=1; i<=n; i++)
        mx[i][0] = mn[i][0] = data[i];
    for(int j=1; j<=k; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r,int flag){
    int k = log2(r-l+1);
    if(flag) return max(mx[l][k],mx[r-(1<<k)+1][k]);
    else return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int a[maxn],b[maxn],c[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        Memset(a, 0);
        Memset(b, 0);
        Memset(c, 0);
        int n;
        ll ans = 0;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        a[n+1]=a[0]=0;
        for (int i=1; i<n; i++) {
            b[i] = abs(a[i+1]-a[i]);
        }
        for (int i=2; i<n; i++) {
            c[i] = abs(a[i+1]-a[i-1]);
        }
        init(b, n-1);
        ans += query(2, n-1, 1);
        ans += query(1, n-2, 1);
        for (int i=2; i<=n-1; i++) {
            int tmp = c[i];
            if (i-2>=1) {
                tmp = max(tmp, query(1, i-2, 1));
            }
            if (i+1<=n-1) {
                tmp = max(tmp, query(i+1, n-1, 1));
            }
            ans +=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
