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
const double eps=1e-10;
const double dx=0.05;
int a,b,y;
double ans;
double f(double x){
    return a*x*x-b*sin(x)-y;
}
bool work(double l , double r){
    if (f(l)*f(r)>0) {
        return false;
    }
    double midl,midr;
    while (r-l>eps) {
        midl = l + (r-l)/3;
        midr = r- (r-l)/3;
        if (fabs(f(midl))<=fabs(f(midr))) {
            r=midr;
        }
        else
            l=midl;
    }
    ans = l;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        cin>>a>>b>>y;
        double l=0;
        bool flag= false;
        while (l<50) {
            if (work(l, l+dx)) {
                flag=true;
                break;
            }
            l+=dx;
        }
        if (flag) {
            printf("%.5f\n",ans);
        }
        else
            printf("error\n");
    }
}
