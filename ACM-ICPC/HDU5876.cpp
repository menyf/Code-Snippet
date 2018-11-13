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
const int maxn=200000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
vector<int> G[maxn],ans;
int dis[maxn];
void bfs(int s,int n){
    memset(dis, INF, sizeof(dis));
    queue<int>q;
    set<int> ta,tb; //未访问结合 以及 当前情况下不可访问集合
    for (int i = 1; i<=n; i++) {
        if (i!=s) {
            ta.insert(i);
        }
    }
    
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i<G[u].size(); i++) {
            int v = G[u][i];
            if (ta.find(v)==ta.end()) continue;
            ta.erase(v);
            tb.insert(v);
        }
        for (set<int>::iterator it = ta.begin(); it!=ta.end(); it++) {
            dis[*it] = dis[u] + 1;
            q.push(*it);
        }
        ta.swap(tb);
        tb.clear();
    }
}
void work(){
    int n,m,s;
    scanf("%d%d",&n,&m);
    
    for (int i = 1; i<=n; i++) {
        G[i].clear();
    }
    for (int i = 1; i<=m; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%d",&s);
    
    bfs(s, n);
    
    ans.clear();
    for (int i = 1; i<=n; i++) {
        if (i==s)
            continue;
        if (dis[i] == INF)
            ans.push_back(-1);
        else
            ans.push_back(dis[i]);
    }
    
    for (int i = 0 ; i<ans.size(); i++) {
        printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
    }
}
int main(){
    int T;
    while (scanf("%d",&T)!=EOF) {
        while (T--) {
            work();
        }
    }
}
