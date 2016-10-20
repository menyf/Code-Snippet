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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define mp make_pair
#define pb push_back
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
/*
 fun1() {    // 取所有奇数位置 再取所有偶数位置
 
 }
 fun2() {    // 中心对称
 
 }
 fun3() {    // 每个数乘方
 
 }
 */
int op[maxn],stp=0,t,n,m;
ll pow_mod(ll A, ll n, ll mod) { //x^n%c
    if (n == 0) return 1;
    ll rslt = 1;
    
    while (n){
        if (n & 1)
            rslt =rslt*A%mod;
        A = A*A%mod;
        n >>= 1;
    }
    return rslt;
}
int main(){
    int pos;
    char s[2];
    scanf("%d",&t);
    int mi=0;
    while (t--) {
        stp=0;
        mi=0;
        scanf("%d%d",&n,&m);
        for (int i=1; i<=m; i++) {
            scanf("%s%d",s,&pos);
            if (s[0]=='O'&&pos==1) {
                op[stp++]=1;
            }
            else if (s[0]=='O'&&pos==2) {
                op[stp++]=0;
            }
            else if (s[0]=='O'&&pos==3) {
                mi++;
            }
            else{
                ll tmp = pos;
                for (int i=stp-1; i>=0; i--) {
                    if (op[i]==1) {
                        if (tmp<=(n+1)/2){
                            tmp=2*tmp-1;
                        }
                        else{
                            tmp=tmp*2-2*(n-n/2);
                        }
                    }
                    else{
                        tmp=n+1-tmp;
                    }
                }
                for (int i=1; i<=mi; i++) {
                    tmp=tmp*tmp%mod;
                }
                printf("%lld\n",tmp);
            }
        }
    }
}
