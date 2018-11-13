// Wrote by MenYifan on 2016-05-18 21:08:27
// Exe.Time 1279ms Exe.Memory 74276K
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
const int maxn=1000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Guest{
    int time,v;
    string name;
    Guest(int t,string n,int val){
        time=t;
        name=n;
        v=val;
    }
    Guest(){}
    bool operator < (const Guest &x) const {
        if(v==x.v)
            return time>x.time;
        else
            return v<x.v;
    }
};
struct Order{
    int t,p;
    Order(int tt,int pp){
        t=tt;
        p=pp;
    }
    Order(){}
    bool operator < (const Order &x) const {
        return t<x.t;
    }
};
Guest guest[150005];
Order order[150005];
string ans[150005];
int main(){
    int t,v;
    char s[205];
    string ss;
    scanf("%d",&t);
    while (t--) {
        int k,m,q,tt,pp;
        scanf("%d%d%d",&k,&m,&q);
        for (int i=0; i<k; i++) {
            scanf("%s%d",s,&v);
            ss=s;
            guest[i]=Guest(i, ss, v);
        }
        for (int i=0; i<m; i++) {
            scanf("%d%d",&tt,&pp);
            order[i]=Order(tt, pp);
        }
        sort(order, order+m);

        priority_queue<Guest>que;
        int incnt=0,outcnt=1;
        for (int i=0; i<m; i++) {
            for (; incnt<order[i].t; incnt++) {
                que.push(guest[incnt]);
            }
            
            for (int j=0; j<order[i].p; j++) {
                ans[outcnt++]=que.top().name;
                que.pop();
                if (que.empty()) {
                    break;
                }
            }
            
        }
        
        for (; incnt<k; incnt++) {
            que.push(guest[incnt]);
        }
        while (!que.empty()) {
            ans[outcnt++]=que.top().name;
            que.pop();
        }
        
        for (int i=0; i<q; i++) {
            scanf("%d",&tt);
            cout<<ans[tt]<<(i==q-1?"\n":" ");
        }
        
    }
}