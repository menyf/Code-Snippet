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
char s[maxn];
string magic[]={"ABAABB", "ABAABBABA","ABAABBABAA","ABAABBABAAB","ABAABBABAABB","ABAABBABAABBA","ABAABBABAABBAB"};
int main(){
	int  T,cas=1;
	scanf("%d",&T);
	while (T--) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		printf("Case #%d:\n",cas++);
		if (m > n) {
			printf("Impossible");
		}
		else if (k <= 2) {
			if (n == m) {
				while (n--) printf("A");
			}
			else{
				if (k==2 && n==8 && m==7) {
					printf("AABBABAA");
				}
				else if (k==2 && m >= 8) {
					int diff = n - m;
					string ans="";
					while (diff > 6) {
						diff -= 6;
						ans += magic[0];
					}
					ans += magic[diff];
					int LEN = ans.length();
					for ( ;LEN<n; LEN++) {
						printf("A");
					}
					cout<<ans;
				}
				else {
					printf("Impossible");
				}
			}
		}
		else {
			if (m < 3) {
				if(n == m) {
					s[n] = 0;
					for(int i=0; i<n; i++)
						s[i] = i % 3 + 'A';
					printf("%s",s);
				} else {
					printf("Impossible");
				}
			}
			else {
				s[n] = 0;
				for (int i = 0 ; i < n ; i++) 
					s[i] = i % 3 + 'A';
				int cnt = m - 3;
				char ch = s[n - 1 - cnt];
				for (int i = 0 , j = n-1 ; i<cnt ; i++, j--)  s[j] = ch;
				printf("%s",s);
			}
		}
		
		
		memset(a, 999, sizeof(a));
		
		if(T) printf("\n");
	}
	return 0;
}
