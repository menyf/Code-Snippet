// Wrote by MenYifan on 2016-04-15 20:55:56
// Exe.Time 514ms Exe.Memory 1600K
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
ll qpow(ll a,int n)
{
    ll rt=1;
    while (n) {
        if (n&1) {
            rt=(a*rt)%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return rt;
}
int main(){
    int t,n;
    cin>>t;
    while (t--) {
        cin>>n;
        cout<<qpow(2,n-1)-1<<endl;
    }
}