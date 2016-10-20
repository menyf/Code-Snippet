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
int bin[100];
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		ll n;
		scanf("%lld",&n);
		int pos = 0;
		while (n!=0) {
			bin[++pos] = n%2;
			n /= 2;
		}
		int ans= 0 ;
		bool flag = false;
		for (int i = 1;i<=pos;i++) {
			if (bin[i] == 1 && !flag) {
				flag = true;
				ans++;
			}
			else if (bin[i] == 0) {
				flag = false;
			}
		}
		cout<<ans<<"\n";
	}
}