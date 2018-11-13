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
const int maxn=1000+5;
int a[maxn];
vector<int> ans;
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1 ; i <= n ;i++) {
		scanf("%d",&a[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = i + 1 ; j <= n ; j++) {
			ans.push_back(a[i] * a[j]);
		}
	}
	int sz = ans.size();
	sort(ans.begin(), ans.end());
	for (int i = sz - 1 ; i >= 0 ; i--) {
		int now = ans[i];
		int pre = now%10;
		now /= 10;
		while (now) {
			int tmp = now % 10;
			if (tmp != pre-1)  break;
			else{
				pre = tmp;
				now /= 10;
			}
		}
		if (now == 0) {
			printf("%d\n",ans[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}