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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+10;
const int Vmax = 2e5 + 10;
const int Emax = 2e6 + 10;
double t,v1,v2;
double sqr(double x){
    return x*x;
}
int main(){
    int T,cas=1;
    double width = 300.0;
    scanf("%d",&T);
    while (T--) {
        bool flag = false;
        scanf("%lf%lf%lf",&t,&v1,&v2);
        if (v1 - v2 >= eps) {
            flag = true;
        }
        else{
            if (2 * sqr(v1) > sqr(v2)) {
                double l = 0, r = 300.0;
                for (int i=0; i<100; i++) {
                    double mid = (l+r)/2;
                    double t1 = sqrt(sqr(mid) + sqr(width)) / v1;
                    double t2 = (mid + width) / v2;
                    if (t1 < t2)
                        r = mid;
                    else
                        l = mid;
                }
                double t1 = (l + 2 * width) / v1;
                double t2 = t + (2 * width - l) / v2;
                if (t1 <= t2) {
                    flag = true;
                }
            }
            else if (3 * v1 > v2){
                double l = 0, r = 300.0;
                for (int i=0; i<100; i++) {
                    double mid = (l+r)/2;
                    double t1 = sqrt(sqr(mid) + sqr(width)) / v1;;
                    double t2 = (3 * width - mid) / v2;
                    if (t1 < t2) {
                        l = mid;
                    }
                    else{
                        r = mid;
                    }
                }
                double t1 = (sqrt(sqr(width - l) + sqr(width)) + 3*width) / v1;
                double t2 = t + (l + width)/v2;
                if (t1 <= t2) {
                    flag = true;
                }
            }
            else{
                flag = false;
            }
        }
        printf("Case #%d: ",cas++);
        if (flag)
            puts("Yes");
        else
            puts("No");
    }
}

