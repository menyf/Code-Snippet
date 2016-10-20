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
const int maxn=1000+5;
int a[1005],tmp[1005];
int bin[maxn];
int mp[maxn][maxn];
int lowbit(int x){
	return x&(-x);
}
void update(int pos,int val){
	while (pos<1005) {
		bin[pos]+=val;
		pos+=lowbit(pos);
	}
}
int sum(int pos){
	int ans=0;
	while (pos>0) {
		ans+= bin[pos];
		pos-=lowbit(pos);
	}
	return ans;
}
int main(){
	int n,q;
	while (scanf("%d%d",&n,&q)!=EOF) {
		for (int i = 1;i<=n;i++) {
			scanf("%d",&a[i]);
			tmp[i] = a[i];
		}
		sort(tmp+1, tmp+1+n);
		ll cnt = unique(tmp+1, tmp+1+n) - tmp - 1;
		for (int i = 1; i<=n ; i++) 
			a[i] = lower_bound(tmp+1, tmp+1+cnt, a[i]) - tmp;
			
		
		for (int i = 1;i <= n;i++) {
			memset(bin, 0, sizeof(bin));
			int len = 0;
			for (int j = i;j <= n;j++) {
				len ++;
				update(a[j], 1);
				mp[i][j] = len - sum(a[j]) + mp[i][j-1];
			}
		}
		for (int i =1;i<=q;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",mp[x][y]);
		}
	}
}