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
map<string,int> mp;
char str[200000+5];
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		mp.clear();
		int n,odd=0,even=0;
		scanf("%d",&n);
		for (int i = 0;i<n;i++) {
			scanf("%s",str);
			string s = str;
			mp[s]++;
			int len = strlen(str);
			if (len % 2)  odd++;
			else  even++;
		}
		int ans = odd * even, tot = n * (n-1) / 2;
		for (map<string, int>::iterator it = mp.begin() ; it != mp.end() ; it++ ) {
			int num = it->second;
			ans += num * (num - 1) / 2;
		}
		if (ans == 0) {
			cout<<"0/1\n";
		}
		else {
			int gcd = __gcd(ans, tot);
			printf("%d/%d\n",ans/gcd,tot/gcd);
		}
	}
	return 0;
}