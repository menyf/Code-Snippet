// Wrote by MenYifan on 2016-08-08 10:03:01
// Exe.Time 374ms Exe.Memory 3940K
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
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll id[maxn],ans[maxn],x[maxn];
int main(){
    int i=0;
    while (scanf("%lld",&id[i])!=EOF) {
        x[i]=id[i];
        i++;
    }
    sort(x, x+i);
    int cnt = unique(x, x+i) - x;

    ll tot = 1,j=0,sum=1;
    for (ll k=1; k<=x[cnt-1]; k++) {
        tot= tot*k%mod;
        sum = sum*tot%mod;
        if (x[j]==k) {
            ans[j]=sum;
            j++;
        }
    }
    
    for (int k=0; k<i; k++) {
        int tmp = lower_bound(x, x+cnt, id[k]) - x;
        cout<<ans[tmp]<<endl;
    }
}