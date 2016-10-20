//
// Untitled 3.cpp
// Created by 门一凡 on 16/10/12.
#include <set>
#include <map>
#include <list>
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
#define fre() freopen("data_in.txt","r",stdin); \
              freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
ll solve(ll x){
    if (x < 6) return 0;
    long double tmp = x;
    ll sqr = sqrt(tmp);
    ll ans = x / 2 - 2;
    if (sqr % 2 == 1) ans++;
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll a,b;
        scanf("%I64d%I64d",&a, &b);
        printf("%I64d\n",solve(b) - solve(a-1));
    }
}
