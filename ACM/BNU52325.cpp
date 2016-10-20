#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
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

//BNU52325
int num[20],pos;
ll dp1[20][10];//20位表示数的长度 10表示前一位的值
ll dp2[20][10][2];//20位表示数的长度 10表示前一位的值 2表示是否是第一位
ll dfs1(int pos, int pre, bool limit){//统计单调递增 pos表示当前位的下标 pre表示前一位的状态 limit表示是否受数字上限大小约束
	if (pos < 1) return 1;
	if (!limit && dp1[pos][pre]!=-1)  return dp1[pos][pre];
	int mx = limit?num[pos]:9;
	ll ret = 0;
	for (int i = pre; i <= mx ; i++) //保证当前位比前一位大
		ret += dfs1(pos-1, i, limit && i == num[pos]);
	if (!limit)  dp1[pos][pre] = ret; //仅存储无约束条件的数 保证记忆化搜索的正确性
	return ret;
}
ll dfs2(int pos, int pre, bool limit, bool first){//单调递减 pos表示当前位的下标 pre表示前一位的状态 limit表示是否受数字上限大小约束 first表示是否是最高位
	if (pos < 1) return 1;
	if (!limit && dp2[pos][pre][first]!=-1)  return dp2[pos][pre][first];
	int mx;
	if (first && limit)  mx = num[pos];
	else if (first && !limit)  mx = 9;
	else if (!first && limit)  mx = min(num[pos], pre);
	else  mx = pre;
	ll ret = 0;
	for (int i = 0; i <= mx ; i++) //保证当前位比前一位小
		ret += dfs2(pos-1, i, limit && i == num[pos], first&&i==0);
	if (!limit)  dp2[pos][pre][first] = ret; //仅存储无约束条件的数 保证记忆化搜索的正确性
	return ret;
}
ll solve(ll x){
	ll tmp = x;
	pos = 0;
	while (x) {
		num[++pos] = x % 10;
		x /= 10;
	}
	ll ret = 0;
	ret += dfs1(pos, 0, true) - 1; //去除0
	ret += dfs2(pos, 9, true, true) - 1; //去除0
	ll bas = 1;
	while (tmp >= bas) { //去除所有位相等的情况 如111, 33333, 55, 6666
		ret -= min(9LL, tmp/bas);
		bas = bas * 10 + 1;
	}
	return ret;
}
int main(){
	//初始化记忆标记
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	
	int n;
	scanf("%d",&n);
	while (n--) {
		ll l,r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n",solve(r) - solve(l-1));
	}
	return 0;
}