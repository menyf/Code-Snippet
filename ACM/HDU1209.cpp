// Wrote by MenYifan on 2015-03-15 22:45:40
// Exe.Time 31ms Exe.Memory 1824K
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<ctype.h>
#define PI acos(-1)
using namespace std;
struct node
{
    int a1,a2;
    float b;
}a[5];
int cmp(node x,node y)
{
    if(x.b!=y.b)return x.b<y.b;
    else if(x.a1!=x.a2)return x.a1<y.a1;
    else return x.a2<y.a2;
}
int main()
{

    int t;
    double b[5];
    scanf("%d",&t);
    int k;
    while(t--){
        for(int i=0;i<5;i++){
            scanf("%2d:%2d",&a[i].a1,&a[i].a2);
        }
        for(int i=0;i<5;i++){
            a[i].b=(a[i].a1%12*1.0*5+double(a[i].a2)/12.0)-a[i].a2;
            if(a[i].b<0)a[i].b=-a[i].b;
            if(a[i].b>30)a[i].b=60-a[i].b;

        }
        sort(a,a+5,cmp);
        printf("%02d:%02d\n",a[2].a1,a[2].a2);
    }
}