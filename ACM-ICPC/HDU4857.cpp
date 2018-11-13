// Wrote by MenYifan on 2016-03-07 19:01:15
// Exe.Time 483ms Exe.Memory 4576K
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
#define rt(n)       (i==n?'\n':' ')
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 30005
int n,m;
vector<int>head[maxn];
int indegree[maxn];
int ans[maxn];
void bfs(){
    int index=n;
    priority_queue<int>q;
    for (int i=1; i<=n; i++) {
        if (indegree[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u=q.top();
        q.pop();
        int sz=head[u].size();
        for (int i=0; i<sz; i++) {
            int v=head[u][i];
            if (--indegree[v]==0) {
                q.push(v);
            }
        }
        ans[index--]=u;
    }
    return;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=0; i<=n; i++) {
            head[i].clear();
            indegree[i]=0;
            ans[i]=0;
        }
        while (m--) {
            int x,y;
            scanf("%d%d",&x,&y);
            head[y].push_back(x);
            indegree[x]++;
        }
        bfs();
        for (int i=1; i<=n; i++) {
            printf("%d%c",ans[i],rt(n));
        }
    }
}