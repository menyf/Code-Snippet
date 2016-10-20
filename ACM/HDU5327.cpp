// Wrote by MenYifan on 2016-04-03 21:09:33
// Exe.Time 15ms Exe.Memory 1992K
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
int c[maxn];
int work(int x){
    int vis[10]={};
    int num=x;
    while (x!=0) {
        if(++vis[x%10]>1){
            return 0;
        }
        x/=10;
    }
    return 1;
}
int main(){
    for (int i=1; i<maxn; i++) {
        c[i]=c[i-1]+work(i);
    }
    int t;
    cin>>t;
    int l,r;
    while (t--) {
        cin>>l>>r;
        cout<<c[r]-c[l-1]<<endl;
    }
    return 0;
}