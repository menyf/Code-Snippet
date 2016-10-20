// Wrote by MenYifan on 2016-09-13 22:10:41
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
/* ?????? */
struct POINT
{
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;} //constructor
    void in(){
        scanf("%lf%lf",&x,&y);
    }
};
struct LINESEG
{
    POINT s;
    POINT e;
    LINESEG(POINT a, POINT b) { s=a; e=b;}
    LINESEG() { }
};
struct LINE           // ??????? a*x+b*y+c=0  ???????? a >= 0
{
    double a;
    double b;
    double c;
    LINE(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;}
};
double dist(POINT p1,POINT p2)                // ??????????
{
    return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
/*
 r=dotmultiply(p1,p2,op),????(p1-op)?(p2-op)???????????????
 r<0??????????
 r=0??????????
 r>0?????????
 *******************************************************************************/
double dotmultiply(POINT p1,POINT p2,POINT p0)
{
    return ((p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y));
}
/* ?????????,?????
 ??????????????P??C???AB???????
 
 AC dot AB
 r =     ---------
 ||AB||^2
 (Cx-Ax)(Bx-Ax) + (Cy-Ay)(By-Ay)
 = -------------------------------
 L^2
 
 r has the following meaning:
 
 r=0      P = A
 r=1      P = B
 r<0   P is on the backward extension of AB
 r>1      P is on the forward extension of AB
 0<r<1  P is interior to AB
 */
double relation(POINT p,LINESEG l)
{
    LINESEG tl;
    tl.s=l.s;
    tl.e=p;
    return dotmultiply(tl.e,l.e,l.s)/(dist(l.s,l.e)*dist(l.s,l.e));
}
// ??C???AB??????? P
POINT perpendicular(POINT p,LINESEG l)
{
    double r=relation(p,l);
    POINT tp;
    tp.x=l.s.x+r*(l.e.x-l.s.x);
    tp.y=l.s.y+r*(l.e.y-l.s.y);
    return tp;
}
/* ??p???l?????,?????????????np
 ???np???l???p??????????? */
double ptolinesegdist(POINT p,LINESEG l,POINT &np)
{
    double r=relation(p,l);
    if(r<0)
    {
        np=l.s;
        return dist(p,l.s);
    }
    if(r>1)
    {
        np=l.e;
        return dist(p,l.e);
    }
    np=perpendicular(p,l);
    return dist(p,np);
}

//???????
//0----?? 1----?? 2----??
int clpoint(POINT p,double r,double a,double b,double c,POINT &rp1,POINT &rp2)
{
    int res=0;
    
    c=c+a*p.x+b*p.y;
    double tmp;
    if(a==0&&b!=0)
    {
        tmp=-c/b;
        if(r*r<tmp*tmp)
            res=0;
        else if(r*r==tmp*tmp)
        {
            res=1;
            rp1.y=tmp;
            rp1.x=0;
        }
        else
        {
            res=2;
            rp1.y=rp2.y=tmp;
            rp1.x=sqrt(r*r-tmp*tmp);
            rp2.x=-rp1.x;
        }
    }
    else if(a!=0&&b==0)
    {
        tmp=-c/a;
        if(r*r<tmp*tmp)
            res=0;
        else if(r*r==tmp*tmp)
        {
            res=1;
            rp1.x=tmp;
            rp1.y=0;
        }
        else
        {
            res=2;
            rp1.x=rp2.x=tmp;
            rp1.y=sqrt(r*r-tmp*tmp);
            rp2.y=-rp1.y;
        }
    }
    else if(a!=0&&b!=0)
    {
        double delta;
        delta=b*b*c*c-(a*a+b*b)*(c*c-a*a*r*r);
        if(delta<0)
            res=0;
        else if(delta==0)
        {
            res=1;
            rp1.y=-b*c/(a*a+b*b);
            rp1.x=(-c-b*rp1.y)/a;
        }
        else
        {
            res=2;
            rp1.y=(-b*c+sqrt(delta))/(a*a+b*b);
            rp2.y=(-b*c-sqrt(delta))/(a*a+b*b);
            rp1.x=(-c-b*rp1.y)/a;
            rp2.x=(-c-b*rp2.y)/a;
        }
    }
    rp1.x+=p.x;
    rp1.y+=p.y;
    rp2.x+=p.x;
    rp2.y+=p.y;
    return res;
}

//??????
// ??????????????
// a1,b1,c1???????(a1 x + b1 y + c1 = 0 ,??)??;
//a2,b2,c2??????????;
//a,b,c??????????.
// ??????????????????:<-b2,a2>??????:<b,-a>.
// ???????????"negative zeros"
void reflect(double a1,double b1,double c1,double a2,double b2,double c2,double &a,double &b,double &c)
{
    double n,m;
    double tpb,tpa;
    tpb=b1*b2+a1*a2;
    tpa=a2*b1-a1*b2;
    m=(tpb*b1+tpa*a1)/(b1*b1+a1*a1);
    n=(tpa*b1-tpb*a1)/(b1*b1+a1*a1);
    if(fabs(a1*b2-a2*b1)<1e-20)
    {
        a=a2;b=b2;c=c2;
        return;
    }
    double xx,yy; //(xx,yy)???????????
    xx=(b1*c2-b2*c1)/(a1*b2-a2*b1);
    yy=(a2*c1-a1*c2)/(a1*b2-a2*b1);
    a=n;
    b=-m;
    c=m*yy-xx*n;
}

bool check1(POINT a,POINT b,double vx,double vy){
    double x = b.x - a.x;
    double y = b.y - a.y;
    if (fabs(x) < eps) { //??
        if (fabs(vx) < eps && vy * y > 0) {
            return true;
        }
        else{
            return false;
        }
    }
    if (fabs(y) < eps) {
        if (fabs(vy) < eps && vx * x > 0 ) {
            return true;
        }
        else{
            return false;
        }
    }
    if (fabs(x * vy - y * vx) < eps && x * vx > 0) {
        return true;
    }
    return false;
}
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int flag = -1;
        POINT A,B,O;
        double vx,vy,R;
        O.in(); scanf("%lf",&R);
        A.in(); scanf("%lf%lf",&vx,&vy);
        B.in();
        
        if (check1(A, B, vx, vy)) {
            POINT tmp;
            LINESEG l = LINESEG(A, B);
            if (ptolinesegdist(O, l, tmp)-R>-eps) {
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
        else{
            POINT p1,p2,c1;
            int status;
            if (vy < 0) {
                status = clpoint(O, R, -vy, vx, -vx*A.y+vy*A.x, p1, p2);
            }
            else{
                status = clpoint(O, R, vy, -vx, vx*A.y-vy*A.x, p1, p2);
            }
            if (status == 2) {
                if (dist(A, p1) < dist(A, p2)) {
                    c1 = p1;
                }
                else{
                    c1 = p2;
                }
                double x0 = O.x - c1.x;
                double y0 = O.y - c1.y;
                double x1 = -y0, y1 = x0;
                double a2,b2,c2;
                reflect(y1,-x1,x1*c1.y-y1*c1.x, vy, -vx, vx*A.y-vy*A.x, a2, b2, c2);
                if (check1(c1, B, b2, -a2)) {
                    flag = 1;
                }
                else
                    flag = 0;
            }
            else{
                flag = 0;
            }
        }
        
        printf("Case #%d: ",++cas);
        if (flag==1) {
            printf("Yes\n");
        }
        else if(flag == 0){
            printf("No\n");
        }
    }
}

/*
 IF ??? <==> ??????????
    IF ????? <==> ?????? >= R
        Yes
    Else
        NO
 Else //??
    IF ???????
        NO
    ELSE
        P1, P2???
        dis(A, P1) < dis(A, P2) ?????P1
        ???
 0 0 1
 ?2 3 1 -2
 ?3 1
 */