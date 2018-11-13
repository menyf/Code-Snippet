// Wrote by MenYifan on 2016-08-23 19:53:30
// Exe.Time 62ms Exe.Memory 1604K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
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
/* ??????? */
const double INF  = 1E200;
const double EP  = 1E-10;
const int  MAXV = 300;

/* ?????? */
struct POINT
{
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;} //constructor
    void in(){ scanf("%lf%lf",&x,&y); }
};

double dist(POINT p1,POINT p2)                // ??????????
{
    return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
int main(){
    int cas = 1;
    POINT p1,p2,p3,rp,mid;
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++) {
        p1.in(),p2.in(),p3.in();
        mid.x = (p2.x + p3.x) / 2;
        mid.y = (p2.y + p3.y) / 2;
    
        double a = dist(p2, p3)/2, b = dist(p1, p2), h = dist(p1, mid);
        double r = a*h/(a+b);
        double R = (a*a-r*r)/r/2+r;
        double ans = 2*R*asin(a/R);
        ans += h;
        
        printf("Case #%d: %.4f\n",cas,ans);
    }
}