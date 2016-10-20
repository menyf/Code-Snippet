// Wrote by MenYifan on 2016-05-05 15:21:12
// Exe.Time 468ms Exe.Memory 1636K
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int ans,n,m,vx,vy;
int mp[105][105];

void Out1() {
	printf("%d\n",ans);

	for(int i=1; i<=m-1; i++) {
		printf("%c",'R');
	}

	if(n == 1) {
		puts("");
	} else {
		int cnt = n/2;

		for(int i=1; i<=cnt; i++) {
			putchar('D');
			for(int j=1; j<=m-1; j++) {
				putchar('L');
			}
			putchar('D');
			for(int j=1; j<=m-1; j++) {
				putchar('R');
			}
		}

		puts("");
	}
}

void Out2() {
	printf("%d\n",ans);

	for(int i=1; i<=n-1; i++) {
		printf("%c",'D');
	}

	if(m == 1) {
		puts("");
	} else {
		int cnt = m/2;

		for(int i=1; i<=cnt; i++) {
			putchar('R');
			for(int j=1; j<=n-1; j++) {
				putchar('U');
			}
			putchar('R');
			for(int j=1; j<=n-1; j++) {
				putchar('D');
			}
		}

		puts("");
	}
}

void Out3() {
	int h =0;
	int cnt = (vx-1)/2;

	for(int i=1; i<=cnt; i++) {
		for(int j=1; j<=m-1; j++) {
			putchar('R');
		}
		putchar('D');
		for(int j=1; j<=m-1; j++) {
			putchar('L');
		}
		putchar('D');
	}

	h+=cnt*2;
	cnt = (vy-1)/2;

	for(int i=1; i<=cnt; i++) {
		putchar('D');
		putchar('R');
		putchar('U');
		putchar('R');
	}

	if(vy%2 == 0) {
		putchar('D');
		putchar('R');
	} else {
		putchar('R');
		putchar('D');
	}

	cnt = (m-vy)/2;

	for(int i=1; i<=cnt; i++) {
		putchar('R');
		putchar('U');
		putchar('R');
		putchar('D');
	}

	h+=2;
	cnt = (n-h)/2;
	if(cnt) {
		for(int i=1; i<=cnt; i++) {
			putchar('D');
			for(int j=1; j<=m-1; j++) {
				putchar('L');
			}
			putchar('D');
			for(int j=1; j<=m-1; j++) {
				putchar('R');
			}
		}
	}
	puts("");
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		ans = 0;
		vx = 1,vy = 2;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%d",mp[i]+j);
				ans+=mp[i][j];
				if(mp[i][j]<mp[vx][vy] && (i+j)&1)vx=i,vy=j;
			}
		}
		if(n&1) {
			Out1();
		} else if(m&1){
			Out2();
		} else {
			printf("%d\n",ans-mp[vx][vy]);
			Out3();
		}
	}
	return 0;
}