//
// Untitled 2.cpp
// Created by 门一凡 on 16/10/7.
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
int a,n;
int num[25],mn,vis[25];
bool cmp (int x,int y){
	return x > y;
}
void dfs(int val, int pos, int step){
	if (step >= mn) return;
	if (val == 0) {
		mn = min(mn, step);
		return;
	}
	for (int i = pos ; i <= n ; i++) 
		if (val >= num[i]) dfs(val % num[i], pos + 1, step + 1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		mn = INF;
		scanf("%d%d",&n,&a);
		for (int i = 1 ;i <= n ; i++) 
			scanf("%d", &num[i]);
		sort(num + 1 , num + 1 + n, cmp);
		dfs(a, 1, 0);
		printf("%d\n",mn==INF?-1:mn);
	}
}