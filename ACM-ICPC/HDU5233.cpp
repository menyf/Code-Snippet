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
int a[maxn],tmp[maxn],sz[maxn],he[maxn];
vector<int> G[maxn];
template <class T>
inline bool Read(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-') ?-1:1 ;
	ret=(c=='-') ?0:(c -'0');
	while(c=getchar(),c>='0'&&c<='9')
		ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}
int main(){
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF) {
		memset(he, 0, sizeof(he));
		memset(sz, 0, sizeof(sz));
		int mx = -1;
		for (int i = 1;i<=n;i++) {
			Read(a[i]);
			mx = max(mx, a[i]);
			tmp[i] = a[i];
		}
		sort(tmp+1, tmp+1+n);
		ll cnt = unique(tmp+1, tmp+1+n) - tmp - 1;
		for (ll i = 0 ;i<=cnt;i++)  vector<int>().swap(G[i]);
		for (ll i = 1;i<=n;i++) {
			int now = lower_bound(tmp+1, tmp+1+cnt, a[i]) - tmp;
			G[now].push_back(i);
			sz[now]++;
		}
		while (m--) {
			int now,q;
			Read(now);
			if (now > mx) {
				cout<<-1<<"\n";
				continue;
			}
			q = lower_bound(tmp+1, tmp+1+cnt, now) - tmp;
			if (tmp[q] != now) {
				cout<<"-1\n";
				continue;
			}
			if (sz[q] == he[q]) cout<<"-1\n";
			else cout<<G[q][he[q]++]<<"\n";
		}
	}
}