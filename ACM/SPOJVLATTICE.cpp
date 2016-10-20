// Wrote by MenYifan on 2016-08-26 21:33:33
// Exe.Time 290ms Exe.Memory 15360K
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
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int normal[maxn];
int mu[maxn];
int prime[maxn];
int pcnt;
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
}
int main(){

    Init();
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n;
        scanf("%lld",&n);
        ll sum = 3;
        for (int i=1; i<=n; i++) {
            sum += mu[i]*(n/i)*(n/i)*(n/i+3);
        }
        cout<<sum<<endl;
    }
    return 0;
}