// Wrote by MenYifan on 2016-09-15 12:47:54
// Exe.Time 265ms Exe.Memory 2736K
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
const int maxn=50000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct node{
    int height,id;
    bool operator < (const node& x)const{
        return height < x.height;
    }
}p[maxn];
struct query{
    int height,id;
    bool operator < (const query& x)const{
        return height < x.height;
    }
}q[maxn];
int tree[maxn];
int ans[maxn];
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        tree[0] = -1;
        tree[n+1] = -1;
        for (int i = 1; i<=n; i++) {
            scanf("%d",&p[i].height);
            p[i].id = i;
            tree[i] = p[i].height;
        }

        for (int i = 1; i<=m; i++) {
            scanf("%d",&q[i].height);
            q[i].id = i;
        }
        
        sort(p+1, p+1+n);
        sort(q+1, q+m+1);
        
        int tot = 1;
        for (int i = 1, j = 1; i<=m; i++) {
            while (j <= n && p[j].height <= q[i].height) {
                int id = p[j].id;
                tree[id] = -1;
                if (tree[id-1]!=-1&&tree[id+1]!=-1)
                    tot++;
                else if (tree[id-1]==-1&&tree[id+1]==-1)
                    tot--;
                j++;
            }
            ans[q[i].id] = tot;
        }
        for (int i = 1; i<=m; i++) {
            printf("%d\n",ans[i]);
        }
    }
}