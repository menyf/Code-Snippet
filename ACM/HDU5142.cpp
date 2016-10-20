// Wrote by MenYifan on 2016-08-08 19:18:10
// Exe.Time 0ms Exe.Memory 1584K
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
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n;
        scanf("%lld",&n);
        int a[100]={};
        int i = 0;
        while (n!=0) {
//            debug(n);
            a[i] = n%2;
            n>>=1;
            i++;
        }
        ll ans = 0;
        for (int j=0; j<i; j++) {
            ans <<=1;
            ans += a[j];
        }
        cout<<ans<<endl;
    }
}