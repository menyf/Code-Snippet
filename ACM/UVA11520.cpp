// Wrote by MenYifan on 2015-10-25 19:50:36
// Exe.Time 0ms Exe.Memory 0K
//
//  20151025c.cpp
//  Cfiles
//
//  Created by ??? on 15/10/25.
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
char s[15][15];
int t,n,cnt;
int vis[15][15]={};
struct Point{
    int x,y;
};
bool cango(int x,int y){
    return x>=1&&x<=10&&y>=1&&y<=10;
}
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
char findit(int x,int y){
    int t[5]={};
    for (int i=0; i<4; i++) {
        if (cango(x+mx[i], y+my[i])) {
            switch (s[x+mx[i]][y+my[i]]) {
                case 'A':
                    t[0]=1;
                    break;
                case 'B':
                    t[1]=1;
                    break;
                case 'C':
                    t[2]=1;
                    break;
                case 'D':
                    t[3]=1;
                    break;
                default:
                    break;
            }
        }
    }
    for (int i=0; i<5; i++) {
        if (t[i]==0) {
            return 'A'+i;
        }
    }
    return 0;
}
int main(){
    
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++) {
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%s",s[i]+1);
        }
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (s[i][j]=='.') {
                    s[i][j]=findit(i,j);
                }
            }
        }
        
        printf("Case %d:\n",cas);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                printf("%c",s[i][j]);
            }
            printf("\n");
        }
    }
}