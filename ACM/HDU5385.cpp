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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int head[maxn],ecnt,dis[maxn];
struct edge{
    int u,v,next;
}e[maxn];
void init(){
    Memset(head, -1);
    Memset(dis, 0);
    ecnt=0;
}
void adde(int u,int v){
    e[ecnt].u=u;
    e[ecnt].v=v;
    e[ecnt].next=head[u];
    head[u]=ecnt++;
}
int main(){
    int n,m,t,x,y;
    scanf("%d",&t);
    while (t--) {
        init();
        scanf("%d%d",&n,&m);
        for (int i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            adde(x,y);
        }
        
        set<int> st;
        for (int i=head[1]; i!=-1; i=e[i].next) {
            st.insert(e[i].v);
        }
        
        dis[1]=0;
        int cnt=1,left=2,right=n,tmp;
        while (cnt!=n) {
            if (st.count(left))
                tmp=left++;
            else
                tmp=right--;
            
            dis[tmp]=cnt++;
            for (int i=head[tmp]; i!=-1; i=e[i].next) {
                st.insert(e[i].v);
            }
        }
        
        for (int i=0; i<m; i++) {
            if (e[i].v==e[i].u)
                printf("%d\n",n);
            else
                printf("%d\n",abs(dis[e[i].u]-dis[e[i].v]));
        }
    }
}

//
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<cstdlib>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<map>
//#include<queue>
//#include<stack>
//#include<string>
//#include<map>
//#include<set>
//#include<ctime>
//#define eps 1e-6
//#define LL long long
//#define pii pair<int, int>
////#pragma comment(linker, "/STACK:1024000000,1024000000")
//using namespace std;
//
//const int MAXN = 100100;
////const int INF = 0x3f3f3f3f;
//struct Edge {
//    int from, to, next;
//} edge[MAXN*2];
//int head[MAXN], tot;
//int n, m, dis[MAXN];
//set<int> s;
//void addedge(int u, int v) {
//    edge[tot].from = u;
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    head[u] = tot++;
//}
//void init() {
//    memset(head, -1, sizeof(head));
//    tot = 0;
//}
//void work() {
//    s.clear();
//    for(int i = head[1]; i != -1; i = edge[i].next) s.insert(edge[i].to);
//    int cnt = 1, left = 2, right = n;
//    dis[1] = 0;
//    while(cnt < n) {
//        int t;
//        if(s.count(left)) t = left++;
//        else t = right--;
//        dis[t] = cnt++;
//        for(int i = head[t]; i != -1; i = edge[i].next) s.insert(edge[i].to);
//    }
//}
//int main() {
//    //freopen("input.txt", "r", stdin);
//    int T; cin >> T;
//    while(T--) {
//        init();
//        cin >> n >> m;
//        for(int i = 1, u, v; i <= m; i++) {
//            scanf("%d%d", &u, &v);
//            addedge(u, v);
//        }
//        work();
//        for(int i = 0; i < m; i++) {
//            int u = edge[i].from, v = edge[i].to;
//            if(u == v) printf("%d\n", n);
//            else printf("%d\n", abs(dis[u]-dis[v]));
//        }
//    }
//    return 0;
//}
