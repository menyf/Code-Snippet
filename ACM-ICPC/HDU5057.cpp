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
#include <deque>
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
int a[100005];
int b[100005];
int c[100005][15];
int ans[100005];
int n , m ;
struct Operation{
    int l , r, d ,p, id;
}op[100005];
int lowbit(int x){
    return x&(-x);
}
void update(int idx,int pos,int val){
    while (idx<=n) {
        c[idx][pos]+=val;
        idx+=lowbit(idx);
    }
}
int sum(int idx,int pos){
    int ans=0;
    while (idx>0) {
        ans+=c[idx][pos];
        idx-=lowbit(idx);
    }
    return ans;
}
int main(){
    char s[10];
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        for (int i=1; i<=m; i++) {
            scanf("%s",s);
            if (s[0]=='Q') {
                scanf("%d %d %d %d",&op[i].l,&op[i].r,&op[i].d,&op[i].p);
                op[i].id=1;
            }
            else{
                scanf("%d %d",&op[i].l,&op[i].r);
                op[i].id=0;
            }
        }
        
        int base=1;
        for (int i=1; i<=10; i++) {
            Memset(c, 0);
            
            for (int j=1; j<=n; j++) {
                b[j]=a[j]/base%10;
                update(j,b[j],1);
            }
            
            for (int j=1; j<=m; j++) {
                if (op[j].id==0) {
                    update(op[j].l,b[op[j].l], -1);
                    b[op[j].l]=op[j].r/base%10;
                    update(op[j].l,b[op[j].l], 1);
                }
                else if(op[j].d==i){
                    ans[j]=sum(op[j].r,op[j].p)-sum(op[j].l-1,op[j].p);
                }
            }
            base*=10;
        }
        
        for (int j=1; j<=m; j++) {
            if (op[j].id) {
                cout<<ans[j]<<endl;
            }
        }
    }
    return 0;
}
