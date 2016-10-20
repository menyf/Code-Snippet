// Wrote by MenYifan on 2016-08-01 20:05:10
// Exe.Time 15ms Exe.Memory 1608K
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
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
double a,b,c,d,L,R;
double dx = 0.00005;
double f(double x){
    return abs(a*x*x*x+b*x*x+c*x+d);
}
int main(){
    while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R)!=EOF) {
        double ans=0;
        if (a==0) {
            if (b!=0) {
                double x0 = -c/(2*b);
                ans = max(f(L), f(R));
                if (L<x0&&x0<R)
                    ans = max(ans, f(x0));
            }
            else
                ans = max(f(L), f(R));
        }
        else{
            double delta = (4*b*b-12*a*c);
            double x1 = (-2*b-sqrt(delta))/(6*a);
            double x2 = (-2*b+sqrt(delta))/(6*a);
            ans = max(f(L), f(R));
            if (L<=x1&&x1<=R)
                ans = max(ans, f(x1));
            if (L<=x2&&x2<=R)
                ans = max(ans, f(x2));
        }
        printf("%.2f\n",ans);
    }
}