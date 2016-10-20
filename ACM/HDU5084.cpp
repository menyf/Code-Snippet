// Wrote by MenYifan on 2016-07-25 21:00:12
// Exe.Time 2511ms Exe.Memory 1608K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int t[1000*3];
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<2*n-1; i++) {
            scanf("%d",&t[i]);
        }
        int m,x,y;
        scanf("%d",&m);
        ll now=0,ans=0;
        while (m--) {
            scanf("%d%d",&x,&y);
            x = ( x + now ) % n;    //?x?
            y = ( y + now ) % n;    //?y?
            now = 0;
            for (int i=0; i<n; i++)
                now += t[n-1-x+i]*t[n-1+y-i];
            ans+=now;
        }
        cout<<ans<<endl;
    }
}