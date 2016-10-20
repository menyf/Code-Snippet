// Wrote by MenYifan on 2016-05-12 22:46:46
// Exe.Time 93ms Exe.Memory 3164K
#pragma comment(linker, "/STACK:10240000000,10240000000")///?????c++???g++???????????
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1e9
#define MIN 1e-8
#define LL long long
#define mys 1000005
#define mode 1000000007
#define debug2 puts("****")
#define blank puts("")
#define pf printf
#define sf scanf
#define mem(a,b) memset(a, b, sizeof(a))
#define memc(a) memset(a, '\0', sizeof(a))
#define debug(x) (cout<<"--- "<<(x)<<" ---"<<endl)
LL a[mys+5],prime[mys+5];
bool isprime[mys+5];
LL gcd(LL a,LL b){
    return b!=0?gcd(b,a%b):a;
}
LL cnt;
LL  inv(LL a,LL m)
{
    if(a==1)
        return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
void getprime()
{
    cnt=0;
    for(int i=0;i<=mys;i++)
    isprime[i]=1;
    for(int i=2;i<=mys;i++)
      if(isprime[i]){
        prime[cnt++]=i;
        for(int j=2*i;j<=mys;j+=i)
            isprime[j]=0;
    }
}
LL mi(LL a){
    LL b=1;
    LL x=mode-2;
    while(x){
        if(x&1)
            b=b*a%mode;
        x>>=1;
        a=a*a%mode;
    }
    return b;
}
int main(){
    getprime();
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        n++;
        LL ans=1;
        for(int i=0;i<cnt&&prime[i]<=n;i++)
        {
            LL tmp=1;
            for(;tmp*prime[i]<=n;)
            tmp=(tmp*prime[i])%mode;
            ans=(ans*tmp)%mode;
        }
        ans=((ans*inv(n,mode))%mode+mode)%mode;
        printf("%I64d\n",ans);
    }
}
