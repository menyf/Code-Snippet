// Wrote by MenYifan on 2015-10-17 18:21:21
// Exe.Time 248ms Exe.Memory 41304K
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
#define maxn 100005
int vis[105][maxn];
int a[105]={},n;
struct point{
    int x,y,moves;
}st,ed;
void BFS(){
    memset(vis, 0, sizeof(vis));
    queue<point>q;
    q.push(st);
    while (!q.empty()) {
        point tmp=q.front();
        point newp;
        q.pop();
        if (tmp.x==ed.x&&tmp.y==ed.y) {
            cout<<tmp.moves<<endl;
            return;
        }
        newp.moves=tmp.moves+1;
        for (int i=0; i<4; i++) {
            if (i==0) {//?
                newp.x=max(1,tmp.x-1);
                newp.y=min(tmp.y, a[newp.x]);
                if (!vis[newp.x][newp.y]) {
                    vis[newp.x][newp.y]=1;
                    q.push(newp);
                }
            }
            else if (i==1){//?
                newp.x=min(tmp.x+1,n);
                newp.y=min(tmp.y, a[newp.x]);
                if (!vis[newp.x][newp.y]) {
                    vis[newp.x][newp.y]=1;
                    q.push(newp);
                }
            }
            else if (i==2){//?
                newp.x=tmp.x;
                newp.y=max(1, tmp.y-1);
                if (!vis[newp.x][newp.y]) {
                    vis[newp.x][newp.y]=1;
                    q.push(newp);
                }
            }
            else{//?
                newp.x=tmp.x;
                newp.y=min(a[newp.x], tmp.y+1);
                if (!vis[newp.x][newp.y]) {
                    vis[newp.x][newp.y]=1;
                    q.push(newp);
                }
            }
        }
        
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        a[i]++;
    }
    scanf("%d %d",&st.x,&st.y);
    scanf("%d %d",&ed.x,&ed.y);
    BFS();
}