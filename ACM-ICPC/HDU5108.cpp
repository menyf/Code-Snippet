// Wrote by MenYifan on 2016-08-03 19:44:25
// Exe.Time 78ms Exe.Memory 2656K
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
ll prime[maxn]={1};
int pcnt=0;//????1~pcnt-1
ll factor[maxn]={1,1}; //factor[i]??i??????
int isPrime(ll num)
{
    if(1 == num || 0 == num)
        return 0;
    int s,t;
    s = sqrt(num);
    for (t = 1; prime[t] <= s; t++)
        if (num%prime[t]==0) return 0;
    return 1;
}
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
    ll n;
    while (cin>>n) {
        if (n<=1) {
            puts("0");
            continue;
        }
        
        if (n<=prime[pcnt-1]&&factor[n]==n) {
            puts("1");
            continue;
        }
        
        ll tmp = n, ans = -1;
        
        for (int i=1; i<pcnt&&prime[i]<n; i++) {
            bool flag = false;
            while (tmp % prime[i]==0) {
                flag = true;
                tmp /= prime[i];
            }
            if (tmp == 1 && flag) {
                ans = prime[i];
                break;
            }
            if (tmp<prime[pcnt-1]&&factor[tmp]==tmp) {
                ans = tmp;
                break;
            }
            else if (tmp>prime[pcnt-1]&&isPrime(tmp)){
                ans = tmp;
                break;
            }
            
            
        }
        
//        debug(n);
//        debug(ans);
        if (ans==-1) {
            printf("1\n");
        }
        else{
            printf("%lld\n",n/ans);
        }
    }
}