// Wrote by MenYifan on 2016-03-21 21:29:52
// Exe.Time 951ms Exe.Memory 17084K
//
//  a.cpp
//  Cfiles
//
//  Created by ??? on 16/3/19.
//  Copyright   2016? ???. All rights reserved.
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
#define rt(n)       (j == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 3000+50
#define mod 1000000007
int n,cnt=0;
int visV[maxn]={},visH[maxn]={};
int cntV[maxn][30]={},cntH[maxn][30]={};
char mp[maxn][maxn]={};
set<char> stV[maxn],stH[maxn];
queue<int>q;
struct node{
    char c,d;
    int p;
    node(){}
    node(char dir,int pos, char col):d(dir),p(pos),c(col){}
}ans[2*maxn];
int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%s",mp[i]+1);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (mp[i][j]!='?') {
                stH[i].insert(mp[i][j]);
                stV[j].insert(mp[i][j]);
                cntH[i][mp[i][j]-'a']++;
                cntV[j][mp[i][j]-'a']++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (stH[i].size()<=1) {
            visH[i]=1;
            q.push(i<<1|1);
            char ch='a';
            if (stH[i].size()) {
                ch=*stH[i].begin();
            }
            ans[cnt++]=node('h', i, ch);
        }
        if (stV[i].size()<=1) {
            visV[i]=1;
            q.push(i<<1);
            char ch='a';
            if (stV[i].size()) {
                ch=*stV[i].begin();
            }
            ans[cnt++]=node('v', i, ch);
        }
    }
    while (!q.empty()) {
        int now=q.front();q.pop();
        int dir=(now&1);
        now>>=1;
        if (dir) {
            for (int i=1; i<=n; i++) {
                if (!visV[i]&&mp[now][i]!='?') {
                    if (--cntV[i][mp[now][i]-'a']==0) {
                        stV[i].erase(mp[now][i]);
                        if (stV[i].size()<=1) {
                            q.push(i<<1);
                            char ch='a';
                            if (stV[i].size()) {
                                ch=*stV[i].begin();
                            }
                            visV[i]=1;
                            ans[cnt++]=node('v', i, ch);
                        }
                    }
                }
            }
        }
        else
        {
            for (int i=1; i<=n; i++) {
                if (!visH[i]&&mp[i][now]!='?') {
                    if (--cntH[i][mp[i][now]-'a']==0) {
                        stH[i].erase(mp[i][now]);
                        if (stH[i].size()<=1) {
                            q.push(i<<1|1);
                            visH[i]=1;
                            char ch='a';
                            if (stH[i].size()) {
                                ch=*stH[i].begin();
                            }
                            ans[cnt++]=node('h', i, ch);
                        }
                    }
                }
            }
        }
    }
    for (int i=cnt-1; i>=0; i--) {
        printf("%c %d %c\n",ans[i].d,ans[i].p,ans[i].c);
    }
}