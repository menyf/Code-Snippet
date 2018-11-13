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
int num[maxn],len;
int main(){
	int n;
	scanf("%d",&n);
	int sum = 0, len = 0;
	for (int i = 1 ; i < maxn ; i++) {
		sum += i;
		if (n <= sum) {
			len = i;
			sum -= i;
			break;
		}
	}
//	debug(len);
	for (int i = 0 ; i < n - sum; i++) {
		putchar(')');
	}
	putchar('(');
	
	for (int i = 0 ; i < len - (n - sum ); i++) {
		putchar(')');
	}
	
	for (int i = 0; i < len - 1 ; i++ ) {
		putchar('(');
	}
	puts("");
	return 0;
}