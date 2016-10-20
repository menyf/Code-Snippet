//
//  20151213c.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/12/13.
//  Copyright &#169; 2015年 门一凡. All rights reserved.
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
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
inline void scan(int &x)
{
    char c; for(c = getchar();c < '0' || c > '9';c = getchar());    x = c - '0';
    for(c = getchar();c >= '0' && c <= '9';c = getchar())   x = (x << 1) + (x << 3) + c - '0';
}
bool cmp(int x, int y){
    return x<y;
}
int main(){
    int c;
    int n,v,w,cnt=0,total=0,sum=0;
    scan(c);
    while (c--) {
        int a[105]={};
        cnt=0;
        total=0;
        sum=0;
        scan(n),scan(v);scan(w);
        for (int i=0; i<n; i++) {
            scan(a[i]);
        }
        sort(a, a+n, cmp);
        for (int i=0; i<n; i++) {
            total+=w;
            sum+=a[i];
            cnt++;
            if (total<sum) {
                cnt--;
                sum-=a[i];
                break;
            }
        }
        if (cnt==0)
            printf("0 0.00\n");
        else
            printf("%d %.2f\n",v*cnt,(float)0.0001*(int)(100*sum/cnt+0.5));
    }
}
