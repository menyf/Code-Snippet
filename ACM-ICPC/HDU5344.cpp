// Wrote by MenYifan on 2016-04-06 18:53:32
// Exe.Time 280ms Exe.Memory 1564K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n,m,z,l,ans=0,tmp,pre=0;
        scanf("%I64d%I64d%I64d%I64d",&n,&m,&z,&l);
        for(int i=2;i<=n;i++)
        {
            tmp=(pre*m+z)%l;
            ans^=(2*tmp);
            pre=tmp;
        }
        printf("%I64d\n",ans);
    }



}
