// Wrote by MenYifan on 2016-09-09 20:23:57
// Exe.Time 15ms Exe.Memory 1588K
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
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-11;
const int maxn=20000+10;
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int ans = -1;
        int cost = INF;
        for (int i=1; i<=m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            int tmp = n/a + (n%a?1:0);
            if (cost > tmp * b) {
                cost = tmp * b;
                ans = i;
            }
        }
        cout<<cost<<"\n";
    }
}