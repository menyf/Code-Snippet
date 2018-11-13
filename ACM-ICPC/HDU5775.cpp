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
#pragma comment(checker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int c[maxn],n,a[maxn],l[maxn],r[maxn],ans[maxn];
int lowbit(int x){
    return x&(-x);
}
void update(int pos, int val){
    while (pos<=n) {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
int sum(int pos){
    int rt=0;
    while (pos>0) {
        rt+=c[pos];
        pos-=lowbit(pos);
    }
    return rt;
}
int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas<=T; cas++) {
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        
        memset(c, 0, sizeof(c));
        for (int i=1; i<=n; i++) {
            update(a[i], 1);
            l[i]=i-sum(a[i]);
//            printf("%d ",l[i]);
        }
//        hi;
        memset(c, 0, sizeof(c));
        for (int i=n; i>=1; i--) {
            update(a[i], 1);
            r[i]=sum(a[i])-1;
//            printf("%d ",r[i]);
        }
//        hi;
        
        for (int i=1; i<=n; i++) {
            ans[a[i]]=abs(i+r[i]-min(i, i+r[i]-l[i]));
        }
        printf("Case #%d:",cas);
        for (int i=1; i<=n; i++) {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
}
