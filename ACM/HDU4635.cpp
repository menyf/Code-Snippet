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
const int maxn=100000+5;
int dfs_clock;//时钟
int scc_cnt;//强连通分量总数
vector<int> G[maxn];//G[i]表示i节点指向的所有点
vector<int> belong[maxn];//belong[i]表示第i个强联通分量包含的所有元素
int pre[maxn]; //时间戳
int low[maxn]; //u以及u的子孙能到达的祖先pre值
int sccno[maxn];//sccno[i]==j表示i节点属于j连通分量 sccno[i]的区间为1~scc_cnt
int cnt[maxn];
stack<int> S;
void dfs(int u){
	pre[u]=low[u]=++dfs_clock;
	S.push(u);
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
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
		belong[scc_cnt].clear();
		while(true){
			int x=S.top(); S.pop();
			sccno[x]=scc_cnt;
			cnt[scc_cnt]++;
			belong[scc_cnt].push_back(x);
			if(x==u) break;
		}
	}
}

//求出有向图所有连通分量
void find_scc(int n){
	scc_cnt=dfs_clock=0;
	memset(sccno,0,sizeof(sccno));
	memset(pre,0,sizeof(pre));
	memset(cnt, 0, sizeof(cnt));
	for(int i=1;i<=n;i++)
		if(!pre[i]) dfs(i);
}
int in[maxn],out[maxn];
void work(int n,int m){
	for(int i=1;i<=n;i++) G[i].clear();
	for (int i = 0 ; i < m ;i++) {
		int u,v;
		scanf("%d%d",&u,&v);//index range: 1~n
		G[u].push_back(v);
	}
	find_scc(n);
	if (scc_cnt == 1) {
		puts("-1");
		return;
	}
	
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	for(int u = 1 ; u <= n; u++){
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			int x = sccno[u], y = sccno[v];
			if(x != y){
				out[x] ++;
				in[y] ++;
			}
		}
	}
	int mn = INF;
	for(int i = 1 ; i <= scc_cnt; i++ ){
		if(in[i] == 0 || out[i] == 0){
			mn = min(mn, cnt[i]);
		}
	}
	ll ans = (ll)n*(n-1) - (ll)mn*(n-mn) - m;
	cout<<ans<<"\n";
}
int main(){
	int n,m,T,cas=1;
	scanf("%d" ,&T);
	while(T--){
		printf("Case %d: ",cas++);
		scanf("%d%d",&n,&m);
		work(n,m);
	}
}