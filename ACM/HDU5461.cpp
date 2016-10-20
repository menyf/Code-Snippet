// Wrote by MenYifan on 2016-08-27 12:33:36
// Exe.Time 514ms Exe.Memory 2940K
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
const int maxn=5000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct node{
    ll num;
    int ord;
    void in(int _ord){
        ord = _ord;
        scanf("%lld",&num);
    }
    bool operator < (const node &a)const{
        return num < a.num;
    }
}p[maxn];
struct mode{
    ll sq;
    int ord;
    bool operator < (const mode &a)const{
        return sq < a.sq;
    }
}q[maxn];
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        ll n,a,b,ans=0;
        scanf("%lld%lld%lld",&n,&a,&b);
        for (int i=1; i<=n; i++) {
            p[i].in(i);
            q[i].ord = i;
            q[i].sq = p[i].num * p[i].num;
        }
        stable_sort(p+1, p+1+n);
        stable_sort(q+1, q+1+n);
        
        if (a>=0&&b>=0) {
            if (p[n].ord != q[n].ord) {
                ans = b*p[n].num+a*q[n].sq;
            }
            else{
                ans = max(b*p[n].num+a*q[n-1].sq, b*p[n-1].num+a*q[n].sq);
            }
        }
        else if (a>=0&&b<0){
            if (q[n].ord!=p[1].ord) {
                ans = a * q[n].sq + b * p[1].num;
            }
            else{
                ans = max(a * q[n].sq + b * p[2].num, a * q[n-1].sq + b * p[1].num);
            }
        }
        else if (a<0&&b>=0){
            if (q[1].ord!=p[n].ord) {
                ans = a *q[1].sq + b * p[n].num;
            }
            else{
                ans = max(a *q[2].sq + b * p[n].num, a *q[1].sq + b * p[n-1].num);
            }
        }
        else if (a<0&&b<0){
            if (q[1].ord != p[1].ord) {
                ans = a *q[1].sq + b * p[1].num;
            }
            else{
                ans = max(a *q[1].sq + b * p[2].num, a *q[2].sq + b * p[1].num);
            }
        }
        
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}

/*
 sort(p+1, p+n+1,cmp2);
 ll ans= 0;
 if (a>0) {
 ans += p[n].sq*a;
 p[n].vis = 1;
 }
 else if(a<0){
 ans += p[1].sq * a;
 p[1].vis = 1;
 }
 sort(p+1, p+n+1, cmp);
 if (b>0) {
 if (p[n].vis==0) {
 ans += b * p[n].num;
 }
 else{
 ans += b*p[n-1].num;
 }
 }
 else{
 if (p[1].vis==0) {
 ans += b * p[1].num;
 }
 else{
 ans += b * p[2].num;
 }
 }
*/