// Wrote by MenYifan on 2016-07-18 18:27:48
// Exe.Time 0ms Exe.Memory 1596K
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    int t;
    ll a, b,c;
    cin>>t;
    while (t--) {
        cin>>a>>b>>c;
        if (c==a||c==b) {
            cout<<"Yes"<<endl;
            continue;
        }
        while (b<c) {
            a=a+b;
            swap(a, b);
        }
        if (b==c||a+b==c) {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
}