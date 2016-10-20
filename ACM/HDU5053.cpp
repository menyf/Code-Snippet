// Wrote by MenYifan on 2016-09-01 12:03:56
// Exe.Time 0ms Exe.Memory 1572K
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
const int maxn=30+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll sum(ll x){
    ll sum = (1 + x)* (x)/2;
    return sum * sum;
}
int main(){
    ll a,b;
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&a,&b);
        if (a>b) {
            swap(a, b);
        }
        printf("Case #%d: %lld\n",cas++,sum(b)-sum(a-1));
    }
}