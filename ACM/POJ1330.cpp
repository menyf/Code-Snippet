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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define pii pair<int,int>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct edge{
	int v,next;
}e[2*maxn];
int he[maxn],ecnt,dep[maxn*2],val[maxn*2],rt[maxn],vis[maxn],top,first[maxn];
int mn[maxn*2][33];
int t,n,x,y;
void adde(int u, int v){
	e[ecnt].v=v;
	e[ecnt].next=he[u];
	he[u]=ecnt++;
}
void init(){
	memset(he, -1, sizeof(he));
	memset(rt, 0, sizeof(rt));
	memset(vis, 0, sizeof(vis));
	ecnt=0;
	top=0;
}
void dfs(int pos, int depth){
	vis[pos]=1;
	dep[top]=depth, val[top]=pos, first[pos]=top++;
//    cout<<pos<<" "<<first[pos]<<endl;
//    printf("depth: %d  value: %d\n",dep[top-1],val[top-1]);
	for (int i=he[pos]; i!=-1; i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			dfs(v,depth+1);
			dep[top]=depth, val[top++]=pos;
//                printf("depth: %d  value: %d\n",dep[top-1],val[top-1]);
		}
	}
}
void prep(){    //ST ???
	for (int i=0; i<top; i++) {
		mn[i+1][0]=i;
	}
	int k = log2(top);
	for (int j=1; j<=k; j++) {
		for (int i=1; i+(1<<j)-1<=top; i++) {
			if (dep[mn[i][j-1]]<dep[mn[i+(1<<(j-1))][j-1]]) {
				mn[i][j]=mn[i][j-1];
			}
			else
				mn[i][j]=mn[i+(1<<(j-1))][j-1];
		}
	}
}
int query(int l, int r){    //ST ??
	int k = log2(r-l+1);
	if (dep[mn[l][k]]<dep[mn[r-(1<<k)+1][k]])
		return mn[l][k];
	else
		return mn[r-(1<<k)+1][k];
}
int main(){
	scanf("%d",&t);
	while (t--) {
		init();
		scanf("%d",&n);
		for (int i=0; i<n-1; i++) {
			scanf("%d%d",&x,&y);
			adde(x, y);
			adde(y, x);
			rt[y]=1;//????
		}
		int root;
		for (int i=1; i<=n; i++) {
			if (rt[i]==0) {
				root=i;
				break;
			}
		}
		dfs(root, 0);
		prep();
//        for (int i=0; i<top; i++) {
//            cout<<dep[i]<<" ";
//        }
//        cout<<endl;
//        for (int i=0; i<top; i++) {
//            cout<<val[i]<<" ";
//        }
//        cout<<endl;
//        
		scanf("%d%d",&x,&y);
		int a = min(first[x], first[y])+1;
		int b = max(first[x], first[y])+1;
//        debug(a);
//        debug(b);
		cout<<val[query(a, b)]<<endl;
	}
}