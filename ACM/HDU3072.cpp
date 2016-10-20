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
#define fre() freopen("data_in.txt","r",stdin); \
			  freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=50000+5;
int dfs_clock;//时钟
int scc_cnt;//强连通分量总数
int pre[maxn]; //时间戳
int low[maxn]; //u以及u的子孙能到达的祖先pre值
int sccno[maxn];//sccno[i]==j表示i节点属于j连通分量 sccno[i]的区间为1~scc_cnt
int w[maxn];
stack<int> S;
struct Edge{
	int v,w,next;
}e[100000+10];
int he[maxn],ecnt= 0;
void adde(int u,int v,int w){
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = he[u];
	he[u] = ecnt++;
}
void dfs(int u){
	pre[u]=low[u]=++dfs_clock;
	S.push(u);
	for (int i = he[u];i != -1;i = e[i].next) {
		int v = e[i].v;
		if(!pre[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!sccno[v]){
			low[u]=min(low[u],pre[v]);
		}
	}
	if(low[u] == pre[u]){//u为当前强连通分量的入口
		scc_cnt++;
		while(true){
			int x=S.top(); S.pop();
			sccno[x]=scc_cnt;
			if(x==u) break;
		}
	}
}

//求出有向图所有连通分量
void find_scc(int n){
	scc_cnt=dfs_clock=0;
	memset(sccno,0,sizeof(sccno));
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++)
		if(!pre[i]) dfs(i);
}
int val[maxn];
void work(int n,int m){
	memset(he, -1, sizeof(he));
	ecnt = 0;
	for (int i = 1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);//index range: 1~n
		u++, v++;
		adde(u, v, w);
	}
	find_scc(n);
	memset(val, INF, sizeof(val));
	for(int u = 1; u <= n; u++){
		for(int i = he[u]; i != -1; i = e[i].next){
			int v = e[i].v;
			int w = e[i].w;
			int x = sccno[u] , y = sccno[v];
			if(x != y) val[y] = min(val[y], w);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= scc_cnt; i++){
		ans += val[i];
	}
	ans -= INF;
	cout<<ans<<"\n";
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		work(n,m);
	}
}