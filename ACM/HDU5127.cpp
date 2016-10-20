#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <list>
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
list<pair<int, int> >v;
int main(){
	int n;
	while (scanf("%d",&n),n) {
		v.clear();
		while (n--) {
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if (op == -1) {
				v.erase(find(v.begin(),v.end(),make_pair(x, y)));
			}
			else if (op == 1) {
				v.push_back(make_pair(x, y));
			}
			else {
				ll mx = -INF;
				for (list<PII>::iterator it = v.begin();it!=v.end();it++) 
					mx = max(mx, (ll)x*it->first+(ll)y*it->second);
				cout<<mx<<"\n";
			}
		}
	}
}