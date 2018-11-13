// Wrote by MenYifan on 2016-08-13 19:17:20
// Exe.Time 62ms Exe.Memory 1800K
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
const int maxn=100+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int n,m;//n?? m??
vector<int>head[maxn];
int indegree[maxn];//????
int topo[maxn];
void init(){
    for (int i=0; i<=n; i++) {
        head[i].clear();
        indegree[i]=0;
        topo[i]=0;
    }
}
bool toposort(){
    int idx=1,cnt=0;
    queue<int>q;
    for (int i=1; i<=n; i++) {
        if (indegree[i]==0) {
            q.push(i);
        }
    }
    if(q.empty()) return false;
    while (!q.empty()) {
        cnt++;
        int u=q.front();
        q.pop();
        topo[idx++]=u;
        int sz=head[u].size();
        for (int i=0; i<sz; i++) {
            int v=head[u][i];
            if (--indegree[v]==0) {
                q.push(v);
            }
        }
    }
    if (cnt==n) {
        return true;
    }else{
        return false;
    }
}
void showAns(){
    for (int i=1; i<=n; i++) {
        printf("%d%c",topo[i],i==n?'\n':' ');
    }
}
int main(){
    int x,y;
    while (scanf("%d%d",&n,&m)!=EOF) {
        init();
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&x,&y);
            head[y].push_back(x);
            indegree[x]++;
        }
        bool ans = toposort();
        if (ans)
            puts("YES");
        else
            puts("NO");
    }
}