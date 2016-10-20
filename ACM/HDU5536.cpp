// Wrote by MenYifan on 2016-10-09 22:17:48
// Exe.Time 8236ms Exe.Memory 1572K

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
const int maxn=100000+5;
int a[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		for (int i =1; i <= n ; i++) {
			scanf("%d",&a[i]);
		}
		int mx = -1;
		for (int i = 1; i <= n ; i++) {
			for (int j = i+1; j <= n ;j++) {
				int tmp = a[i] + a[j];
				for (int k = 1; k <= n; k++) {
					if (i == k || j == k) continue;
					mx = max(mx, tmp^a[k]);
				}
			}
		}
		printf("%d\n",mx);
	}	
}