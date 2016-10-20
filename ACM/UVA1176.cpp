#include <cstdio>
int bitcount(int n){
	return n?((n&1) + bitcount(n>>1)):0;
}
int main(){
	int n;
	while (scanf("%d",&n)!=EOF) {
		printf("%d\n", n+(1<<bitcount(n))-1);
	}
}
