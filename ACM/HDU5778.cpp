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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll prime[maxn]={1};
int pcnt=0;//素数下标1~pcnt-1
ll factor[maxn]={1,1}; //factor[i]表示i的最小质因子
void Init_Prime(){
    pcnt=1;
    for(ll i = 2 ; i < maxn ; i ++){
        if(!factor[i]) {
            prime[pcnt++]=i;
            factor[i]=i;
        }
        for(ll j = 1 ; j < pcnt && i * prime[j] <  maxn ; j ++)
        {
            factor[i * prime[j]] = prime[j];
            if( !(i % prime[j] ) )
                break;
        }
    }
    return;
}
bool judge(ll x){
    for (int i=1; i<=pcnt&&prime[i]*prime[i]<x; i++) {
        if (x%prime[i]==0) {
            x/=prime[i];
            if (x%prime[i]==0) {
                return false;
            }
        }
    }
    return true;
}
int main(){
    Init_Prime();
    int T;
    scanf("%d",&T);
    while (T--) {
        ll x;
        cin>>x;
        ll up = sqrt(x);
        ll down = up;
        while (up*up<x) {
            up++;
        }
        while (down*down>x) {
            down--;
        }
        
        while (!judge(up)) {
            up++;
        }
        up = max(2LL, up);
        while (!judge(down)) {
            down--;
        }
        down = max(2LL, down);
        ll ans =min(abs(x-down*down), abs(x-up*up));
        cout<<ans<<endl;
    }
}
