// Wrote by MenYifan on 2015-11-09 15:48:03
// Exe.Time 3ms Exe.Memory 0K
//
//  20151108g.cpp
//  Cfiles
//
//  Created by ??? on 15/11/8.
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
int n,ans,sCnt;
double o,r,l,w;
bool flag=false;
struct segment{
    double l,r;
}s[maxn];
bool cmp(segment a,segment b){
    return a.l<b.l;
}
int main(){
    while (scanf("%d%lf%lf",&n,&l,&w)!=EOF) {
        flag=false;
        ans=sCnt=0;
        for (int i=0; i<n; i++) {
            scanf("%lf%lf",&o,&r);
            if(w/2>=r) continue; //??????????
            double tmp=sqrt(r*r-w*w/4.0);
            s[sCnt].l=o-tmp;
            s[sCnt++].r=o+tmp;
        }
        
        sort(s, s+sCnt, cmp);
        
        if (s[0].l>0) {
            printf("-1\n");
            continue;
        }
        
        int index=0;
        double left=0,right=0;
        while (index<sCnt) {
            int tmp=index;
            while (tmp<sCnt&&s[tmp].l<=left) {
                right=max(right, s[tmp++].r);
            }
            
            if (tmp==index) break;
            
            ans++;
            index=tmp;
            left=right;
            if (left>=l) {
                flag=true;
                break;
            }
        }
        
        if (flag) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}