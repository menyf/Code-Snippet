// Wrote by MenYifan on 2016-08-30 13:08:33
// Exe.Time 452ms Exe.Memory 1568K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int bit[50];
int main(){
    ll n;
    int s1,s2,T,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%d%d",&n,&s1,&s2);
        int Bitcnt = 0, len =0;
        while (n!=0) {
            bit[++len] = n & 1;
            n >>= 1;
            if (bit[len])
                Bitcnt++;
        }
        
        if (Bitcnt == len) {
            Memset(bit, 0);
            bit[++len] = 1;
            for (int i=1; i<=s1-1; i++) {
                bit[i] = 1;
            }
        }
        else{
            if (bit[1]==0) {
                if (Bitcnt < s2) {
                    bit[1] = 1;
                }
                else{
                    int i,cnt=0;
                    for (i=2; i<=len; i++) {
                        if (bit[i]) {
                            cnt++;
                        }
                        else if(cnt){
                            break;
                        }
                    }
                    if (i==len+1) {
                        Memset(bit, 0);
                        bit[++len] = 1;
                        for (int i=1; i<=s1-1; i++) {
                            bit[i] = 1;
                        }
                    }
                    else{
                        bit[i] = 1;
                        for (int j = 1; j<i; j++) {
                            bit[j] = 0;
                        }
                        for (int j = 1; j<=s1-(Bitcnt-cnt+1); j++) {
                            bit[j] = 1;
                        }
                    }
                }
            }
            else{
                int pos;
                for (pos=1 ; pos<=len; pos++) {
                    if (bit[pos]==0) {
                        break;
                    }
                    else
                        bit[pos] = 0;
                }
                int rest = Bitcnt - (pos - 1) + 1;
                bit[pos] = 1;
                for (int i=1; i<=s1-rest; i++) {
                    bit[i] = 1;
                }
            }
        }
        
//        for (int i=len; i>=1; i--) {
//            printf("%d",bit[i]);
//        }
//        
        ll ans = 0;
        for (int i = len; i>=1; i--) {
            ans <<= 1;
            ans += bit[i];
        }
        
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}


/*
 if (Bitcnt < len) {
 if (Bitcnt==1) {
 bit[len] = 0;
 bit[++len] = 1;
 }
 else{
 int cnt = 0,pos;
 for (int i=1; i<=len; i++) {
 if (cnt&&bit[i]==0){
 pos = i;
 break;
 }
 else{
 if (bit[i]) {
 cnt++;
 }
 }
 bit[i] =  0;
 }
 bit[pos] =1;
 int rest = Bitcnt - cnt + 1;
 for (int i=1; i<=s1 - rest; i++) {
 bit[i] = 1;
 }
 
 }
 
 }
 else{
 len ++;
 memset(bit, 0, sizeof(bit));
 bit[len] = 1;
 for (int i=1; i<=s1 - 1; i++) {
 bit[i] = 1;
 }
 }
 
 */