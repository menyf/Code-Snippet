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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int fcnt=120005;
ll qpow(ll a,ll n){
    if (n==0) {
        return 1;
    }
    ll rt = 1;
    while (n) {
        if (n&1) {
            rt = rt*a%mod;
        }
        a = a*a %mod;
        n>>=1;
    }
    return rt;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        ll n , m;
        cin>>n>>m;
        cout<<(qpow(m, n+1)-1+mod)%mod*qpow(m-1, mod-2)%mod<<endl;
    }
}
