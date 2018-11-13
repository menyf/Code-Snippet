// Wrote by MenYifan on 2016-04-11 18:13:43
// Exe.Time 655ms Exe.Memory 9788K
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define db(n) cout<<n<<endl

const int NV=100005;
const int NE=100005*6;
int he[NV],ecnt;
int view[NE],in[NV],out[NV];

struct edge
{
    int v,next;
} E[NE];

void adde(int u,int v)
{
    E[++ecnt].v=v;
    E[ecnt].next=he[u];
    he[u]=ecnt;
}

void dfs(int u,int k) {
	for (int i=he[u]; i!=-1; i=E[i].next){
		if(view[i]==-1) {
			he[u] = E[i].next;

			if(k==0) {
				in[u]++;
				out[E[i].v]++;
			} else {
				out[u]++;
				in[E[i].v]++;
			}

			if(i&1) {
				view[i] = view[i+1] = k;
			} else {
				view[i] = view[i-1] = k^1;
			}

			dfs(E[i].v,k);
			return;
		}
	}
	he[u] = -1;
	return;
}

void unit() {
	ecnt=0;
	memset(he,-1,sizeof(he));
	memset(view,-1,sizeof(view));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		unit();

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			adde(a,b);
			adde(b,a);
		}

		for(int i=1;i<=n;i++) {
			while(he[i]!=-1) {
				int k = (in[i]-out[i]<0?0:1);
				dfs(i,k);
			}
		}

		for(int i=1;i<=m;i++) {
			printf("%d\n",view[2*i-1]);
		}
	}
	return 0;
}