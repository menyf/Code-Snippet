// Wrote by MenYifan on 2016-09-01 16:34:38
// Exe.Time 0ms Exe.Memory 1576K
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;// SSSSSB
int main() {
	int T;
	scanf("%d",&T);
	for(int cas=1; cas<=T; cas++) {
		int n,b,q;
		scanf("%d%d%d",&n,&b,&q);
		if(q == 1) {
			if(b == n || b / 10 == n || b / 100 == n || b / 1000 == n) printf("Case #%d: 1.00000\n",cas);
			else printf("Case #%d: 0.00000\n",cas);
		} else if(q == 10 || q == 100 || q == 1000) {
			if(b == n || b / 10 == n || b / 100 == n || b / 1000 == n || b * 10 == n || b * 100 == n || b * 1000 == n) printf("Case #%d: 1.00000\n",cas);
			else printf("Case #%d: 0.00000\n",cas);
		}else {
			printf("Case #%d: %.5f\n",cas,log(n+1)/log(10) - log(n)/log(10));
		}
	}
	return 0;
}