// Wrote by MenYifan on 2016-09-06 12:15:14
// Exe.Time 9ms Exe.Memory 0K
//HDU 3849
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
const double eps=1e-8;
//?????????
const int maxn=10000+10;
int id[maxn];
int main(){
    int n;
    char s[2];
    while (scanf("%d",&n)!=EOF) {
        int ans = 0;
        for (int i=1; i<=n; i++) {
            scanf("%s",s);
            if (s[0]!='S') {
                scanf("%d",&id[i]);
                if (id[i]==1) {
                    ans ++;
                }
            }
            else{
                ans ++;
            }
        }
        cout<<ans<<'\n';
    }
}