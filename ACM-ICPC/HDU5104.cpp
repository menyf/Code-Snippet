// Wrote by MenYifan on 2016-08-01 19:10:03
// Exe.Time 62ms Exe.Memory 1628K
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
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int prime[maxn]={1};
int pcnt=0;//????1~pcnt-1
int factor[maxn]={-1,-1}; //factor[i]??i??????
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

int main(){
    Init_Prime();
//    debug(pcnt);
//    
//    for (int i=1; i<pcnt; i++) {
//        debug2(i, prime[i]);
//    }
    
    int n;
    while (scanf("%d",&n)!=EOF) {
        int ans=0;
        for (int i=1; i<pcnt&&prime[i]<=n; i++) {
            for (int j=i; j<pcnt&&prime[j]<=n; j++) {
                int tmp = n - prime[i]-prime[j];
                if (tmp>=prime[i]&&tmp>=prime[j]&&factor[tmp]==tmp) {
                    ans++;

                }
                
            }
        }
        cout<<ans<<endl;
    }
}