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
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=50000+5;
string s[maxn];
ll tot;
void dfs(int pos, int l, int r){
	if (pos == 30 || l > r) return;
	int left = l,right = l;
	for (;left <= r;left++) 
		if (s[left][pos] == '1') 
			break;
	right = left--;
	tot += (ll)(1 << pos) * (left - l + 1) % mod * (r - right +1) % mod;
	dfs(pos+1, l, left);
	dfs(pos+1, right, r);	
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while (T--) {
		tot=0;
		int n;
		scanf("%d",&n);
		for (int i = 1;i<=n;i++) {
			int tmp;
			scanf("%d",&tmp);
			s[i] = "";
			int len = 0;
			while (tmp) {
				s[i] += tmp % 2 +'0';
				tmp /= 2;
				len++;
			}
			while (len<30) {
				s[i]+='0';
				len++;
			}
		}
		sort(s+1, s+1+n);
		dfs(0, 1, n);
		printf("Case #%d: %lld\n",cas++,tot*2%mod);
	}
}