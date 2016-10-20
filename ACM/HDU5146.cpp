// Wrote by MenYifan on 2016-08-10 19:03:31
// Exe.Time 15ms Exe.Memory 1576K
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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[1005];
bool judge(int a[],int n){
    for (int i=1; i<=n/2; i++) {
        if (a[i]!=a[n-i+1]) {
            return true;
        }
    }
    return false;
}
int main(){
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        ll odd= 0, even = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d",a+i);
            if (i%2) {
                odd += a[i];
            }
            else
                even += a[i];
        }
        if (odd == even && judge(a , n)) {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}