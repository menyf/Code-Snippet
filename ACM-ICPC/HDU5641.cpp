//
//  bc75b2.cpp
//  Cfiles
//
//  Created by 门一凡 on 16/3/12.
//  Copyright &#169; 2016年 门一凡. All rights reserved.
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
#define maxn 100000+5
#define mod 1000000007
int vis[10],v[10];
bool ok(int x,int y){
    if (x>y) {
        swap(x, y);
    }
    if (x==1&&y==3&&vis[2]==0) {
        return false;
    }
    if (x==4&&y==6&&vis[5]==0) {
        return false;
    }
    if (x==7&&y==9&&vis[8]==0) {
        return false;
    }
    if (x==1&&y==7&&vis[4]==0) {
        return false;
    }
    if (x==2&&y==8&&vis[5]==0) {
        return false;
    }
    if (x==3&&y==9&&vis[6]==0) {
        return false;
    }
    if (x==1&&y==9&&vis[5]==0) {
        return false;
    }
    if (x==3&&y==7&&vis[5]==0) {
        return false;
    }
    return true;
}
int main(){
    int t,k,tmp;
    scanf("%d",&t);
    while (t--) {
        bool flag=true;
        scanf("%d",&k);
        Memset(vis,0);
        for (int i=0; i<k; i++) {
            scanf("%d",&tmp);
            if (!flag||tmp==0||tmp>9||vis[tmp]) {
                flag=false;
                continue;
            }
            vis[tmp]++;
            v[i]=tmp;
        }
        
        Memset(vis,0);
        
        vis[v[0]]=1;
        
        for (int i=1; i<k; i++) {
            flag=flag&&ok(v[i-1], v[i]);
            vis[v[i]]=1;
        }
        
        if (flag&&k>3) {
            printf("valid\n");
        }
        else
            printf("invalid\n");
    }
}
