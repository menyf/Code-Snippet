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
const int maxn=100000+5;
vector<int>v[2160000+5];
int main(){

	for (int h = 0; h < 12 ; h++) {
		for (int m = 0; m < 60 ;m++) {
			for (int s = 0;s < 60 ;s += 10) {
				int mm = 72000*m+s*1200;
				int hh = 360000*h + 6000*m+100*s;
				int now = abs(hh - mm);
				now = min(now, 2160000-(now-2160000));
				int tmp = h * 3600 + m *60 + s;
				if (h == 4 && m == 21 && s == 50) {
					debug(now);
				}
				v[now].push_back(tmp);
			}	
		}
	}
	int n;
	while (scanf("%d",&n)!=EOF) {
		sort(v[n].begin(), v[n].end());
		for (int i = 0;i<v[n].size();i++) {
			printf("%02d:%02d:%02d\n",v[n][i]/3600,(v[n][i]%3600/60),v[n][i]%60);
		}
	}
}