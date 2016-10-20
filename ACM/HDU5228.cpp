// Wrote by MenYifan on 2016-09-22 19:18:06
// Exe.Time 0ms Exe.Memory 1592K
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
char s[10][2];
int num[5][15];
int main(){
	int T;
	scanf("%d" ,&T);
	while (T--) {
		memset(num, 0, sizeof(num));
		for (int i = 1;i<=5;i++) {
			int tmp;
			scanf("%1s%d",s[i],&tmp);
//			printf("%s%d ",s[i], tmp);
			if (s[i][0] =='A') {
				if (tmp == 1) {
					num[1][14]++;
					num[1][1]++;
				}
				else {
					num[1][tmp]++;
				}
			}
			else if (s[i][0] =='B') {
				if (tmp == 1) {
					num[2][14]++;
					num[2][1]++;
				}
				else {
					num[2][tmp]++;
				}
			}
			else if (s[i][0] =='C') {
				if (tmp == 1) {
					num[3][14]++;
					num[3][1]++;
				}
				else {
					num[3][tmp]++;
				}
			}
			else if (s[i][0] =='D'){
				if (tmp == 1) {
					num[4][14]++;
					num[4][1]++;
				}
				else {
					num[4][tmp]++;
				}
			}
		}
		
//		for (int i = 1;i<=4;i++) {
//			for (int j = 1;j<=15;j++) {
//				printf("%d ",num[i][j]);
//			}
//			puts("");
//		}
//		
		int mx = 0;
		for (int i = 1;i<=4;i++) {
			for (int j = 1;j+5<=15;j++) {
//				printf("%d ",num[i][j]);
				int cnt = 0;
				for (int k = 0;k<5;k++) {
					if (num[i][j+k]) {
//						debug(j);
						cnt++;
					}
				}
				mx = max(mx, cnt);
			}
//			puts("");
		}
		cout<<5-mx<<"\n";
	}
}