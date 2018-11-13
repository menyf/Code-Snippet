//参考链接：http://blog.csdn.net/caduca/article/details/47154213

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
int main(){
    unsigned long long a[4];
    int t;
    scanf("%d",&t);
    while (t--) {
        for (int i=0; i<4; i++) {
            cin>>a[i];
        }
        sort(a, a+4);
        if (a[0]!=0&&a[0]+a[1]>a[3]-a[2])
             printf("Yes\n");
        else
            printf("No\n");
        
    }
    return 0;
}
