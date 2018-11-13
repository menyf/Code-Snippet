// Wrote by MenYifan on 2016-08-26 17:30:08
// Exe.Time 780ms Exe.Memory 95684K
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn = 500005;
int normal[maxn];
int mu[maxn];
int prime[maxn];
int pcnt;
LL sum[maxn][22];
LL num[maxn];
void Init()
{
    memset(normal,0,sizeof(normal));
    mu[1] = 1;
    pcnt = 0;
    for(int i=2; i<maxn; i++)
    {
        if(!normal[i])
        {
            prime[pcnt++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<pcnt&&i*prime[j]<maxn; j++)
        {
            normal[i*prime[j]] = 1;
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];
            else
            {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }

    memset(num,0,sizeof(num));
    num[1] = 0;
    for(int i=0; i<pcnt; i++) {
    	for(int j=prime[i]; j<=maxn-5; j+=prime[i]) {
    		int tmp = j;
    		while(tmp % prime[i] == 0) {
    			tmp /= prime[i];
    			num[j] ++;
    		}
    	}
    }

    memset(sum,0,sizeof(sum));
    for(int i=1; i<=maxn-5; i++) {
    	for(int j=i; j<=maxn-5; j+=i) {
    		sum[j][num[i]] += mu[j/i];
    	}
    }
    for(int i=1; i<=maxn-5; i++) {
    	for(int j=0; j<=18; j++) {
    		sum[i][j] += sum[i-1][j];
    	}
    }
    for(int i=1; i<=maxn-5; i++) {
    	for(int j=1; j<=18; j++) {
    		sum[i][j] += sum[i][j-1];
    	}
    }
}

int main() {
	Init();
	int T;
	scanf("%d",&T);
	while(T--) {
		LL n,m,p;
		scanf("%lld%lld%lld",&n,&m,&p);
		if(p>=19) {
			printf("%lld\n",n*m);
			continue;
		}
		if(n > m) swap(n,m);
		for(int i=0; i<=min(n,m); i++) {
		    //printf("sum: %lld\n",sum[i][p]);
		}
		LL ans = 0;
		for(LL i=1,j; i<=n; i=j+1) {
			j = min(n/(n/i),m/(m/i));
			ans += (sum[j][p] - sum[i-1][p]) * (n/i) * (m/i);
			//printf("i: %lld  ans: %lld\n",i,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}