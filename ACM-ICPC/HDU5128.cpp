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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=30+5;
int mp[205][205];
struct node{
	int x,y;
	node(){}
	node(int _x,int _y){
		x = _x, y = _y;
	}
}p[maxn];
struct block{
	int l,r,u,d;
	int area;
	block(){}
	block (node _a,node _b){
		l = min(_a.x, _b.x);
		r = max(_a.x, _b.x);
		d = min(_a.y, _b.y);
		u = max(_a.y, _b.y);
		area = (u-d)*(r-l);
	}
	void show(){
		printf("%d %d %d %d\n",l,r,d,u);
	}
	bool operator < (const block &a)const{
		if (l!=a.l) {
			return  l < a.l;
		}
		else if (r != a.r) {
			return r < a.r;
		}
		else if (u != a.u) {
			return u < a.u;
		}
		else {
			return d < a.d;
		}
	}
	bool operator == (const block &a)const{
		return l == a.l && r == a.r && d == a.d && u == a.u;
	}
}b[1005];
bool in(int x,int y, block a){
	return a.l<=x&&x<=a.r&&a.d<=y&&y<=a.u;
}
bool fuck(block a,block b){
	return a.l>b.l && a.r<b.r && a.u < b.u && a.d > b.d;
}
int main(){
	int n;
	while (scanf("%d",&n),n) {
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= n ;i++) {
			scanf("%d%d",&p[i].x,&p[i].y);
			mp[p[i].x][p[i].y] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n;i++) {
			for (int j = i+1;j <= n; j++) {
				if (p[i].x == p[j].x || p[i].y == p[j].y) continue;
				if (mp[p[i].x][p[j].y] && mp[p[j].x][p[i].y]) {
					b[++cnt] = block(p[i], p[j]);
				}
			}
		}
		int area= 0;
		sort(b+1, b+1+cnt);
		int bcnt = unique(b+1, b+1+cnt) - b - 1;
		
		for (int i = 1; i<=bcnt;i++) {
			int l = b[i].l, r = b[i].r, u = b[i].u, d = b[i].d;
			for (int j = i+1; j <= bcnt; j++) {
				if (in(b[i].l, b[i].u, b[j]) == false && in(b[i].r, b[i].u, b[j]) == false && in(b[i].l, b[i].d, b[j]) == false && in(b[i].r, b[i].d, b[j]) == false && in(b[j].l, b[j].u, b[i]) == false && in(b[j].r, b[j].u, b[i]) == false && in(b[j].l, b[j].d, b[i]) == false && in(b[j].r, b[j].d, b[i]) == false) {
					area = max(area, b[i].area + b[j].area);
				}
				if (fuck(b[i], b[j])) {
					area = max(area, b[j].area);
				}
				if (fuck(b[j], b[i])) {
					area = max(area, b[i].area);
				}
			}
		}
	
		if (area == 0) 
			printf("imp\n");
		else 
			cout<<area<<"\n";
	}
}