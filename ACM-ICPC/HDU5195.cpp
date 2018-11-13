// Wrote by MenYifan on 2016-09-12 22:00:22
// Exe.Time 530ms Exe.Memory 8100K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
vector<int>G[maxn];
int in[maxn];
vector<int> ans;
int vis[maxn];
int n,m,k;
void work(){
    ans.clear();
    memset(vis, 0, sizeof(vis));
    priority_queue<int>q;
    for (int i = 1; i<=n; i++)
        if (in[i] == 0) q.push(i);
    int now = n;
    while (in[now] > k) now--;//??
    while (!q.empty()) {
        int u = q.top(); q.pop();
        if (vis[u]) continue;
        if (now > 0) {
            if (now == u) {
                ans.push_back(u); vis[u] = 1;
                for (int i = 0; i<G[u].size(); i++) {
                    int v = G[u][i];
                    if (!vis[v] && --in[v] == 0) {
                        q.push(v);
                    }
                }
                now--;
                while (now > 0 && (in[now] > k || vis[now])) now--;
            }
            else{
                if (now > u) {
                    ans.push_back(now); vis[now] = 1; k-=in[now];
                    for (int i = 0; i<G[now].size(); i++) {
                        int v = G[now][i];
                        if (!vis[v] && --in[v] == 0) q.push(v);
                    }
                    now--; q.push(u);
                    while (now > 0 && (in[now] > k || vis[now])) now--;
                }
                else{
                    ans.push_back(u); vis[u] = 1;
                    for (int i = 0; i<G[u].size(); i++) {
                        int v = G[u][i];
                        if (!vis[v] && --in[v] == 0) {
                            q.push(v);
                        }
                    }
                }
            }
        }
        else{
            ans.push_back(u); vis[u] = 1;
            for (int i = 0; i<G[u].size(); i++) {
                int v = G[u][i];
                if (!vis[v] && --in[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
        memset(in, 0, sizeof(in));
        for (int i = 1; i<=n; i++) G[i].clear();
        for (int i = 1; i<=m; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            in[v]++;
        }
        work();
        for (int i = 0; i<ans.size(); i++) {
            printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
        }
    }
    return 0;
}

/*
 data:
 4 7 4
 2 3
 3 4
 3 4
 3 4
 1 4
 1 4
 1 4
 
 ans: 3 4 2 1
 data watered
 */