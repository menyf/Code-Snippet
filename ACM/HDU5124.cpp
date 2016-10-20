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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
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
const int mod=110119;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int x[maxn],y[maxn],tmp[maxn<<1];
int c[maxn*2];
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        Memset(c, 0);
        int n;
        scanf("%d",&n);
        int j = 1;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&x[i],&y[i]);
            tmp[j++]=x[i];
            tmp[j++]=y[i];
        }
        sort(tmp+1, tmp+j);
        
        int cnt = unique(tmp+1, tmp+j)-tmp-1;
        

        for (int i=0; i<n; i++){
            x[i]=lower_bound(tmp+1, tmp+1+cnt, x[i])-tmp;
            y[i]=lower_bound(tmp+1, tmp+1+cnt, y[i])-tmp;
            c[x[i]]++;
            c[y[i]+1]--;
        }
        int ans = 0;
        for (int i=1; i<=cnt; i++) {
            c[i]+=c[i-1];
            ans = max(ans, c[i]);
        }
        cout<<ans<<endl;
    }
}
