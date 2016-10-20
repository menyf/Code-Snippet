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
ll n,a[20],p[20],l,r,cas=0,T;
ll mult_mod(ll a,ll b,ll mod){  //快速乘
    return (a*b-(ll)(a/(long double)mod*b+1e-3)*mod+mod)%mod;
}
ll ex_gcd(ll a,ll b,ll &x,ll &y){   //扩展欧几里得求ax+by=gcd(a,b)的整数解
    ll d;
    if (!b) {
        x=1,y=0;
        return a;
    }
    d =ex_gcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}
ll Bitcount(ll x){  //计算x所含的二进制位数
    return x==0?0:Bitcount(x>>1)+(x&1);
}
ll crt(ll a[], ll p[], ll M, ll k){ //中国剩余定理
    ll ans=0;
    for (int i=0; i<=k; i++) {
        ll x,y,mi = M/p[i];
        ll gcd = ex_gcd(p[i], mi, x, y);
        ll tmp =mult_mod(y, mi, M);
        tmp = mult_mod(tmp, a[i], M);
        ans = (ans + tmp) % M;
    }
    return (ans + M) % M;
}
ll get_ans(ll x){   //找到小于等于x的范围内，符合条件的数量
    ll ta[20],tp[20],t,i,num,top,j;
    if (x==0) {
        return 0;
    }
    ll ans=0;
    ta[0]=0,tp[0]=7;    //保证是七的倍数
    for (i=1; i<(1<<n); i++) {  //二进制枚举
        num = Bitcount(i);
        t = 7;
        top = 0;
        for (j=0; j<n; j++) {
            if ((i>>j)&1) {
                ta[++top]=a[j];
                tp[top]=p[j];
                t*=p[j];
            }
        }
        ll res = crt(ta, tp, t, top);   //中国剩余定理求出符合条件的值
        if (x<res) continue;   //大于要求的x，过掉
        
        /* 容斥原理 */
        if (num&1)  //奇减偶加，得到的ans值为负数，ans的绝对值表示有多少个是7的倍数且模p[]为a[]的数量
            ans+=(x-res)/t+1;
        else
            ans-=(x-res)/t+1;
    }
    return  x/7 - ans;
}
int main(){
    scanf("%lld",&T);
    for (cas=1; cas<=T; cas++) {
        scanf("%lld%lld%lld",&n,&l,&r);
        for (int i=0; i<n; i++) {
            scanf("%lld%lld",p+i,a+i);
        }
        printf("Case #%lld: %lld\n",cas,get_ans(r)-get_ans(l-1));
    }
}
