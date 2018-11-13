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
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
#define Vmax 35
#define Emax 1005
int he[Vmax],ecnt,now;
struct edge{
	int v,next;
	ll w;
}e[Emax*2];
ll dis[Vmax];
int vcnt[Vmax];//记录每个点进队次数，用于判断是否出现负环
bool inq[Vmax];
int pre[Vmax];  //记录最短路中的上一个节点
void init(){
	ecnt=0;
	memset(he,-1,sizeof(he));
}
//***注意双向加边
void adde(int from,int to,ll w){
	e[ecnt].v=to;
	e[ecnt].w=w;
	e[ecnt].next=he[from];
	he[from]=ecnt++;
}
bool SPFA(int n,int source){//n为顶点数 source为起点
	memset(vcnt,0,sizeof(vcnt));
	memset(inq, false, sizeof(inq));
	//return true表示无负环，反之亦然
	for (int i=0; i<=n; i++) {
		dis[i]=INF;
		//debug(dis[i]);
	}
	dis[source]=0;
	queue<int>q;
	q.push(source);inq[source]=true;

	while (!q.empty()) {
		int tmp=q.front();
		q.pop();inq[tmp]=false;

		//判断负环
		vcnt[tmp]++;
		if (vcnt[tmp]>=n) return false;

		for (int i=he[tmp]; i!=-1; i=e[i].next) {
			int w=e[i].w;
			int v=e[i].v;
			if(v == now) continue;
			if (dis[tmp]+w<dis[v]) {
				dis[v]=dis[tmp]+w;  //松弛操作
				pre[v]=tmp;
				if (!inq[v]) {
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
	return true;
}
long long  get_ans(int n,int source,int destination){
	SPFA(n,source);
	return dis[destination];
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n){
		init();
		while(m--){
			int u,v;
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			adde(u, v, w);
			adde(v, u, w);
		}
		ll ans = 0;
		for(now = 2; now < n; now ++){
			ll tmp = get_ans(n, 1, n);
			ans = max(ans, tmp);
		}
		if(ans == INF) cout<<"Inf\n";
		else cout<<ans<<"\n";
	}
}