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
const int maxn=1000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct node{
    int val;
    int lson,rson;
}a[maxn];
void insert(int rt,int val){
    if (val > rt) {
        if (a[rt].lson==0)
            a[rt].lson = val;
        else
            insert(a[rt].lson,val);
    }
    else{
        if (a[rt].rson ==0)
            a[rt].rson = val;
        else
            insert(a[rt].rson,val);
    }
    
}
void query(int rt,int val){
    if (rt==val) {
        return;
    }
    else if (rt<val){
        printf("W");
        query(a[rt].lson, val);
    }
    else if (rt>val){
        printf("E");
        query(a[rt].rson, val);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,q;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            a[i].lson = 0;
            a[i].rson = 0;
        }
        int rt,tmp;
        scanf("%d",&rt);
        for (int i=2; i<=n; i++) {
            scanf("%d",&tmp);
            insert(rt, tmp);
        }
        scanf("%d",&q);
        while (q--) {
            scanf("%d",&tmp);
            query(rt, tmp);
            puts("");
        }
    }
    return 0;
}
