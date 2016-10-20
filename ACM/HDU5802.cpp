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
ll p,q,cnt;
ll bits[50];
ll work(ll st,ll ed, ll stop,ll step){
    if (st<=ed) {
        return ed- st+step ;
    }
    int k = 0;
    while (st - bits[k] > ed)
        k++;
    
    if (max(st - bits[k], 0LL) == ed)
        return k+step;
    
    ll up = ed - max(0LL, st - bits[k]);
    ll tmp =  step  + k + max(0LL, up - stop);
    
    return min(tmp, work(st - bits[k-1], ed, stop + 1, step + k));
    
    return 0;
}
int main(){
    for (int i=1; i<32; i++) {
        bits[i] = 1LL<<(i-1);
    }
    for (int i = 1; i<32; i++) {
        bits[i]+=bits[i-1];
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        cnt =0 ;
        scanf("%lld%lld",&p,&q);
        printf("%lld\n",work(p, q, 0, 0));
    }
}
