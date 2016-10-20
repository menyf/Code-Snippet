#include <set>
#include <map>
#include <list>
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
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
const int maxn=1000+5;
struct edge{
	int u,v;
}e[maxn * maxn];
int mp[maxn][maxn];
int main(){
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF) {
		for (int i = 0;i<n;i++) {
			scanf("%*d%*d");
		}
		memset(mp, 0, sizeof(mp));
		for (int i = 1 ; i <= m; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			mp[u][v] = mp[v][u] = 1;
			e[i] = (edge){u, v};
		}
		if ( m == 0) {
			printf("1 %d\n", n);
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= m ; i++) {
			for (int j = i+1 ; j <= m ; j++) {
				edge &a = e[i];
				edge &b = e[j];
				if (a.u != b.u && a.v != b.v && a.u != b.v && a.v != b.u) {
					if (mp[a.u][b.u] && mp[a.v][b.v] && mp[a.u][b.v] && mp[a.v][b.u]) {
						cnt++;
					}
				}
			}
		}
		if (cnt) {
			printf("4 %d\n",cnt / 3);
			continue;
		}
		
		for (int i = 1; i <= m;i++) {
			int u = e[i].u, v = e[i].v;
			for (int j = 1; j <= n ; j++) {
				if (u != j && v != j && mp[u][j] && mp[v][j]) {
					cnt++;
				}
			}
		}
		if (cnt) {
			printf("3 %d\n",cnt / 3);
			continue;
		}
		
		printf("2 %d\n", m);
	}
}