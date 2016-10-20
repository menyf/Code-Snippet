// Wrote by MenYifan on 2016-08-19 19:02:44
// Exe.Time 15ms Exe.Memory 1564K
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
int vis[1005];
int main(){
    int T,n,tmp;
    scanf("%d",&T);
    while (T--) {
        Memset(vis, 0);
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&tmp);
            vis[tmp]=1;
        }
        int cnt = 0;
        for (int i=1; i<=1005; i++) {
            if (vis[i]==0) {
                if (cnt==0) {
                    printf("%d ",i);
                    cnt++;
                }
                else{
                    printf("%d\n",i);
                    break;
                }
                
                
            }
            
        }
    }
}