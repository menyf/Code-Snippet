// Wrote by MenYifan on 2016-02-08 13:46:17
// Exe.Time 15ms Exe.Memory 1616K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <sstream>
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
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    int a[maxn];
    int n,m;
    while (~scanf("%d %d",&n,&m)) {
        for (int i=0; i<=n; i++) {
            a[i]=i;
        }
        m--;
        while (m--) {
            next_permutation(a+1, a+1+n);
        }
        for (int i=1; i<=n; i++) {
            cout<<a[i]<<rt(n);
        }
    }
}