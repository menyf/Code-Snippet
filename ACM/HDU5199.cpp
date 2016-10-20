// Wrote by MenYifan on 2016-09-14 19:15:57
// Exe.Time 1154ms Exe.Memory 13332K
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
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn],tmp[maxn],num[maxn];
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(num, 0, sizeof(num));
        for (int i = 1; i<=n; i++) {
            scanf("%d",&a[i]);
            tmp[i] = a[i];
        }
        sort(tmp+1, tmp+1+n);
        int cnt = unique(tmp+1, tmp+1+n) - tmp - 1;
        for (int i = 1; i<=n; i++) {
            int now = lower_bound(tmp+1, tmp+1+cnt, a[i]) - tmp;
            num[now]++;
        }
        while (m--) {
            int now;
            scanf("%d",&now);
            now = lower_bound(tmp+1, tmp+1+cnt, now) - tmp;
            if (num[now]!=0) {
                cout<<num[now]<<"\n";
                num[now] = 0;
            }
            else{
                cout<<"0\n";
            }
        }
        
    }
}