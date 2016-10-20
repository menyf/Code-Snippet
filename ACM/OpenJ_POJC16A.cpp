// Wrote by MenYifan on 2016-05-09 18:30:20
// Exe.Time 0ms Exe.Memory 508K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
double l[maxn],r[maxn];
int main(){
    int t;
    int n;
    double p;
    scanf("%d",&t);
    while (t--) {
        int ans=0;
        cin>>n>>p;
        for (int i=1; i<=n; i++) {
            cin>>l[i]>>r[i];
            if (l[i]<=p&&r[i]>=r[ans]) {
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}