// Wrote by MenYifan on 2016-09-16 19:07:58
// Exe.Time 62ms Exe.Memory 1592K
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
const int maxn=10000+10;
struct node{
    ll x,y,z;
    void in(){
        scanf("%lld%lld%lld",&x,&y,&z);
    }
};
ll dis(node a,node b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    ll dz = a.z - b.z;
    return dx*dx+dy*dy+dz*dz;
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        printf("Case #%d: ",cas++);
        node a[5];
        for (int i = 1; i<=4; i++) {
            a[i].in();
        }
        set<ll> st;
        for (int i = 1; i<=4; i++) {
            for (int j = i+1; j<=4; j++) {
                st.insert(dis(a[i], a[j]));
            }
        }
        ll tmp1 = *st.begin();
        set<ll> ::iterator it = st.begin();
        tmp1 = *it;
        it++;
        ll tmp2 = *it;
        if (st.size() == 2 && tmp1*2 == tmp2) {
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";

    }
}