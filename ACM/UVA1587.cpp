// Wrote by MenYifan on 2015-10-11 18:28:08
// Exe.Time 0ms Exe.Memory 0K
//
//  20151011a.cpp
//  Cfiles
//
//  Created by ??? on 15/10/11.
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
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define vset(a,val) memset(a,val,sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
struct node{
    int w,h,area;
}a[6];
bool cmp(node x,node y){
    if (x.area!=y.area) {
        return x.area<y.area;
    }
    else
        return x.w<y.w;
}
int getnode(int x,int s){
    if (s==0) {
        return a[x].w;
    }
    else
        return a[x].h;
}


int main(){
    int side[]={0,1};
    while (scanf("%d %d",&a[0].h,&a[0].w)!=EOF) {
        a[0].area=a[0].h*a[0].w;
        for (int i=1; i<6; i++) {
            scanf("%d %d",&a[i].h,&a[i].w);
            a[i].area=a[i].h*a[i].w;
        }
        for (int i=0; i<6; i++) {
            if (a[i].h<a[i].w) {
                swap(a[i].h, a[i].w);
            }
        }
        sort(a, a+6, cmp);
        
        for (int i=0; i<6; i+=2) {
            if (a[i].area!=a[i+1].area) {
                cout<<"IMPOSSIBLE"<<endl;
                goto tag;
            }
        }
        
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    if (getnode(4, k)==getnode(2, j)&&
                        getnode(0, i)==getnode(4, 1-k)&&
                        getnode(0, 1-i)==getnode(2, 1-j)) {
                        cout<<"POSSIBLE"<<endl;
                        goto tag;
                    }
                }
            }
        }
        
        cout<<"IMPOSSIBLE"<<endl;
        
    tag:continue;
    }
}