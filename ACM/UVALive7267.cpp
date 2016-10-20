// Wrote by MenYifan on 2016-09-06 12:39:43
// Exe.Time 3ms Exe.Memory 0K
//HDU 3849
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=10000+10;
struct node{
    int w,h;
    node(){}
    node(int _w,int _h){
        w = _w;
        h = _h;
    }
    void in(){
        scanf("%d%d",&w,&h);
    }
}p[5],mp[5][5][5];
bool cmp(node x,node y){
    return x.w==y.w||x.h==y.h||x.w==y.h||x.h==y.w;
}
int vis[5][5];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        for (int i=1; i<=4; i++) {
            p[i].in();
        }
        for (int i=1; i<=4; i++) {
            for (int j=i+1; j<=4; j++) {
                int &now = vis[i][j];
                if (p[i].w == p[j].w) {
                    mp[i][j][now++]=node(p[i].w, p[i].h+p[j].h);
                }
                if (p[i].h == p[j].h) {
                    mp[i][j][now++] = node(p[i].h,p[i].w+p[j].w);
                }
                if (p[i].w == p[j].h) {
                    mp[i][j][now++] = node(p[i].w,p[i].h+p[j].w);
                }
                if (p[i].h == p[j].w) {
                    mp[i][j][now++] = node(p[i].h,p[i].w+p[j].h);
                }
            }
        }
        bool flag = false;
        for (int i=1; i<=4; i++) {
            for (int j=i+1; j<=4; j++) {
                for (int k =1 ; k<=4; k++) {
                    if (k == i || k==j) {
                        continue;
                    }
                    for (int q =0; q<vis[i][j]; q++) {
                        if (cmp(mp[i][j][q], p[k])) {
                            flag = true;
                        }
                    }
                }
            }
        }
        if (flag) {
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }
}