// Wrote by MenYifan on 2015-11-15 18:40:57
// Exe.Time 3ms Exe.Memory 0K
//
//  20151115c.cpp
//  Cfiles
//
//  Created by ??? on 15/11/15.
//  Copyright   2015? ???. All rights reserved.
//

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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
struct point{
    double x,y;
}p[9];
double area(point a,point b,point c){
    return (0.5)*(a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y);
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        for (int i=0; i<3; i++) {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        double ans=area(p[0], p[1], p[2])/7;
        if (ans-(int)ans>0.5) {
            cout<<(int )ans+1<<endl;
        }
        else{
            cout<<(int)ans<<endl;
        }
    }
}