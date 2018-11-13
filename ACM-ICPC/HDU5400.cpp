// Wrote by MenYifan on 2016-05-05 20:45:09
// Exe.Time 561ms Exe.Memory 2736K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn],l[maxn],r[maxn];
int main(){
    int n,d1,d2;
    while (scanf("%d%d%d",&n,&d1,&d2)!=EOF) {
        for (int i=0; i<n; i++)
            scanf("%d",&a[i]);
        
        for (int i=0; i<n; i++)
            if (i&&a[i]-a[i-1]==d1)
                l[i]=l[i-1]+1;
            else
                l[i]=1;
        
        for (int i=n-1; i>=0; i--)
            if (i!=n-1&&a[i+1]-a[i]==d2)
                r[i]=r[i+1]+1;
            else
                r[i]=1;
        
        ll sum=0;
        
        if (d1==d2)
            for (int i=0; i<n; i++)
                sum+=(ll)l[i];
        else
            for (int i=0; i<n; i++)
                sum+=(ll)l[i]*r[i];

        printf("%lld\n",sum);
    }
}