//M. Subimage Recognition
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
int n,m,N,M;
char mp1[25][25],mp2[25][25];
vector<int>row;
bool dfs1(int r, int pos1, int pos2){
	if (pos2 == m){
		int i = 0, j = 0; //i for mp1, j for mp2
		while (i < N && j < n) {
			bool flag = true;
			for (int k = 0; k < row.size() && flag; k++) 
				if (mp1[i][row[k]] != mp2[j][k]) flag = false;
			if (flag) j++;
			i++;
		}
		if (j == n) return true;
		else return false;
	}
	for (int i = pos1 ; i < M ; i++) {
		if (mp1[r][i] == mp2[0][pos2]) {
			row.push_back(i);
			if (dfs1(r, i+1, pos2+1)) return true;
			else row.pop_back();
		}
	}
	return false;
}
int main(){
	while (scanf("%d%d",&n,&m)!=EOF) {
		row.clear();
		for (int i = 0 ; i < n ; i++) scanf("%s",mp2[i]);
		scanf("%d%d", &N, &M);
		for (int i = 0 ; i < N ; i++) scanf("%s",mp1[i]);
		if (n > N || m > M) printf("No\n");
		else {
			bool flag = false;
			for (int i = 0; i <= N-n && !flag; i++) 
				if (dfs1(i, 0, 0)) flag = true;
			if (flag) printf("Yes\n");
			else printf("No\n");
		}
	}
}
