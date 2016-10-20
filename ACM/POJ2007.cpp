#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define maxn 55
#define eps 1e-8
struct Node{
    double x,y;
}p[maxn];
int mul(Node p1,Node p2){
    return p1.x*p2.y-p1.y*p2.x;
}
int cmp(Node p1,Node p2){
    return mul(p1, p2)>0;
}
int main(){
    int n=0;
    while (scanf("%lf %lf",&p[n].x,&p[n].y)!=EOF) {
        n++;
    }
    sort(p+1, p+n, cmp);
    for (int i=0; i<n; i++) {
        printf ("(%.0f,%.0f)\n", p[i].x, p[i].y);
    }
}
