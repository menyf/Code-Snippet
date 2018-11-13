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
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn = 100000+10;
vector<int> G[maxn];
int c[maxn];
int main(){
	int T;
	scanf("%d", &T);
	while(T--) {
		
		int n,m;
		scanf("%d%d",&n,&m);  
		for (int i = 1 ; i <= n ; i++) G[i].clear();
		for (int i = 1 ; i <= m ; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (n < 2) {
			puts("Poor wyh");
			continue;
		}
		if (m == 0) {
			printf("%d %d\n",n-1, 1);
			continue;
		}
		
		/* --START---交叉染色---START--- */
		memset(c, -1, sizeof(c)); //标记所有颜色
		bool flag = true; //判断是否可以完成染色
		queue<int>q;
		int mx = 0, mn = 0;
		bool flag = true;
		for (int i = 1; i <= n && flag ; i++) {
			if (c[i] == -1) {
				int tmp1 = 0, tmp2 = 0;	
				q.push(i);
				c[i] = 1;
				while (!q.empty() && flag) {
					int u = q.front(); q.pop();
					if (c[u] == 1)  tmp1++;
					else tmp2++;
					for (int i = 0; i < G[u].size() && flag ; i++) {
						int v = G[u][i];
						if (c[v] == -1) {
							c[v] = c[u]^1;
							q.push(v);
						}
						else if (c[v] != c[u]^1) 
							flag = false;
					}
				}
				mx += max(tmp1, tmp2);
				mn += min(tmp2, tmp1);
			}	
		}
		if (flag) printf("%d %d\n",mx,mn);
		else puts("Poor wyh");
		/* --END---交叉染色---END--- */
	}
}