// Wrote by MenYifan on 2016-09-03 20:10:20
// Exe.Time 78ms Exe.Memory 1964K
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
struct node{
    int a,b;
    bool operator < (const node &x) const {
        return b < x.b;
    }
}p[maxn];
int vis[maxn],N,cnt[maxn],tmp[maxn];
int f(int n){   //????
    for (int i=0; i<maxn; i++) {
        tmp[i] = cnt[i];
        vis[i] = 0;
    }
    int rt = 0;
    for (int i=1; i<=N; i++) {
        if (tmp[p[i].a] > n) {
            tmp[0]++;
            rt += p[i].b;
            tmp[p[i].a]--;
            vis[i] = 1;
        }
    }
    for (int i=1; i<=N; i++) {
        if (tmp[0] <= n && !vis[i]) {
            rt += p[i].b;
            tmp[0] ++;
            tmp[p[i].a]--;
        }
    }
    return rt;
}
int main(){
    scanf("%d",&N);
    for (int i=1; i<=N; i++) {
        scanf("%d%d",&p[i].a,&p[i].b);
        cnt[p[i].a]++;
    }
    sort(p+1, p+N+1);
    int l = 0, r = 1e5;
    while (l < r - 1) {
        int mid = (r + l) >> 1;
        int mmid = (mid + r) >> 1;
        if (f(mid) <= f(mmid)) {
            r = mmid;
        }
        else{
            l = mid;
        }
    }
    int ans = INF;
    for (int i = l; i<=r; i++) {
        ans = min(ans, f(i));
    }
    cout<<ans<<'\n';
}