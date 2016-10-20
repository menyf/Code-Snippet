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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
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
int he[maxn],n,k,ecnt,x,y;
struct edge{
    int v,next;
}e[maxn*2];
struct node{
    int st,ed,len;
    node(){}
    node(int _st,int _ed,int _len){
        st = _st;
        ed = _ed;
        len = _len;
    }
};
queue<node>q;
void adde(int u,int v){
    e[ecnt].v=v;
    e[ecnt].next=he[u];
    he[u]=ecnt++;
}
void init(){
    memset(he, -1, sizeof(he));
    while (!q.empty()) q.pop();
    ecnt=0;
    scanf("%d%d",&n,&k);
    for (int i=1; i<n; i++) {
        scanf("%d%d",&x,&y);
        adde(x, y);
        adde(y, x);
    }
    for (int i=1; i<=n; i++) {
        q.push(node(i, i, 0));
    }
    k<<=1;
}

int bfs(){
    int cnt=0;
    int ans=0;
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        int u = tmp.st , v = tmp.ed, len = tmp.len;
        for (int i=he[u]; ~i; i=e[i].next) {
            if (e[i].v==v) continue;
            ans+=len+1;
            if (++cnt==k) return ans;
            q.push(node(e[i].v, u, len+1));
        }
    }
    return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        init();
        cout<<bfs()/2<<endl;
    }
    return 0;
}
