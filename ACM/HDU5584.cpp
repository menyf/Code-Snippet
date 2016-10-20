// Wrote by MenYifan on 2016-09-13 20:39:41
// Exe.Time 15ms Exe.Memory 1572K
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;

LL solve(int x,int y) 
{
	if(x > y) swap(x,y);
	int gcd = __gcd(x,y);
	x /= gcd, y /= gcd;
	if(y % (x + 1) != 0) return 1;
	else return 1 + solve(y / (x + 1), x);
}

int main() {
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++)
	{
		int ex,ey;
		scanf("%d%d",&ex,&ey);
		LL ans = solve(ex,ey);
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}