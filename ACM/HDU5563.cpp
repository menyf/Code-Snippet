//
//  Clarke and five-pointed star(b).cpp
//  Cfiles
//
//  Created by 门一凡 on 15/11/14.
//  Copyright &#169; 2015年 门一凡. All rights reserved.
//

#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-4
#define INF 0x3f3f3f3f
#pragma comment(linker, "/st:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define MAXN 10
int mp[5][5];
struct point{
    double x,y;
    
}p[5];

double dis(point p1,point p2){  //计算 p1p2的 距离
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
double max(double a,double b){
    if (a>b)
        return a;
    else
        return b;
}

int main()
{
    int t,index;
    double mx;
    double vis[10];
    bool flag;
    scanf("%d",&t);
    while (t--) {
        mx=0;
        index=0;
        flag=true;
        for (int i=0; i<5; i++) {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        
        for (int i=0; i<5; i++) {
            for (int j=i+1; j<5; j++) {
                vis[index++]=dis(p[i],p[j]);
            }
        }
        
        sort(vis, vis+10);
//        debug;
        
        for (int i=1; i<5; i++) {
            if (fabs(vis[i]-vis[i-1])>eps) {
//                cout<<i<<endl;
                flag=false;
            }
        }
        
        for (int i=6; i<10; i++) {
            if (fabs(vis[i]-vis[i-1])>eps) {
                flag=false;
            }
        }
        
        if (flag) {
            printf("Yes\n");
        }
        else
            printf("No\n");
        
    }
    
}

