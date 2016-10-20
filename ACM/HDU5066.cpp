// Wrote by MenYifan on 2016-07-22 19:08:37
// Exe.Time 0ms Exe.Memory 1572K
#include <set>
#include <map>
#include <stack>
#include <cmath>
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
#define pii pair<int,int>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    ll v1,v2;
    while (scanf("%lld%lld",&v1,&v2)!=EOF) {
        cout<<2*v1-v2<<endl;
    }
}