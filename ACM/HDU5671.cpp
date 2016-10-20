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
const int maxn=1000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int mp[maxn][maxn];
int r[maxn],c[maxn],addr[maxn],addc[maxn];
int main(){
    int t,n,m,q,op,x,y;
    scanf("%d",&t);
    while (t--) {
        cin>>n>>m>>q;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                scanf("%d",&mp[i][j]);
            }
        }
        for (int i=1; i<=n; i++) {
            r[i]=i;
            addr[i]=0;
        }
        for (int i=1; i<=m; i++) {
            c[i]=i;
            addc[i]=0;
        }
        while (q--) {
            scanf("%d%d%d",&op,&x,&y);
            if (op==1) {
                swap(r[x], r[y]);
            }
            else if (op==2){
                swap(c[x], c[y]);
            }
            else if (op==3){
                addr[r[x]]+=y;
            }
            else{
                addc[c[x]]+=y;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                printf("%d%c",mp[r[i]][c[j]]+addr[r[i]]+addc[c[j]],j==m?'\n':' ');
            }
        }
    }
}

