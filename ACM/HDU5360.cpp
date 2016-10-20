// Wrote by MenYifan on 2016-04-14 19:34:19
// Exe.Time 1232ms Exe.Memory 4524K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int ans[maxn];
struct node
{
    friend bool operator< (node n1, node n2)
    {
        if(n1.r==n2.r) return n1.l>n2.l;
        return n1.r > n2.r;
    }
    int l,r,id;
    node(int ll=0,int rr=0,int idd=0):l(ll),r(rr),id(idd)
    {}
}a[maxn];
bool cmp(node x,node y){
    if (x.l==y.l) {
        return x.r<y.r;
    }
    return x.l<y.l;
}


int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i].l);
        }
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i].r);
            a[i].id=i;
        }
        sort(a+1, a+n+1, cmp);//?????????
        priority_queue<node> q;//???????????????
        int id1=1,id2=1,i;
        for (i=0; i<n; i++) {
            //?????i??push????????????????????
            while (a[id1].l==i) {
                q.push(a[id1++]);
            }
            //?????i????????
            while (!q.empty()&&q.top().r<i) {
                ans[id2++]=q.top().id;
                q.pop();
            }
            if (!q.empty()) {
                //????????>=i??
                ans[id2++]=q.top().id;
                q.pop();
            }
            else
                break;
        }
        for (; id1<=n; id1++) {
            ans[id2++]=a[id1].id;
        }
        printf("%d\n",i);
        for (int i=1; i<=n; i++) {
            printf("%d%c",ans[i],i==n?'\n':' ');
        }
    }
}
/*
 4
 8
 4 1 3 2 2 1 0 3
 5 3 6 4 2 1 7 6
 7
 7 6 5 2 4 1 3 8
 8
 3 3 2 0 5 0 3 6
 4 5 2 7 7 6 7 6
 8
 6 4 3 1 2 5 8 7
 8
 2 2 3 3 3 0 0 2
 7 4 3 6 3 2 2 5
 7
 6 7 2 3 8 4 1 5
 8
 5 6 5 3 3 1 2 4
 6 7 7 6 5 4 3 5
 0
 1 2 3 4 5 6 7 8
 */