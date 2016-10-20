// A - Distribution money
// Untitled.cpp
// Created by 门一凡 on 16/10/10.
#include <set>
#include <map>
#include <list>
#include <assert.h>
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
int a[maxn];
int main(){
	int n;
	while (scanf("%d",&n)!=EOF) {
		memset(a, 0, sizeof(a));
		for (int i = 0 ; i < n ; i++) {
			int tmp;
			scanf("%d",&tmp);
			a[tmp]++;
		}
		int ans = -1;
		for (int i = 1; i <= 10000; i++) {
			if (2 * a[i] > n) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;	
}