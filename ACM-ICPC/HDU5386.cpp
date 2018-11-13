/*
 11 : 6
 12 : 8
 13 : 4
 14 : 10
 15 : 8
 16 : 8
 17 : 8
 18 : 16
 19 : 10
 20 : 16
 21 : 12
 22 : 12
 23 : 14

 
 */
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
int a[105][105],ed[105][105],ans[505];
struct node{
    char dir;
    int pos,val;
    int id;
    node(char d,int p,int v,int idd){
        dir=d;
        pos=p;
        val=v;
        id=idd;
    }
    node(){}
};
int main(){
    int t,n,m,p,v;
    char ch[2];
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                scanf("%d",&ed[i][j]);
            }
        }
        queue<node>q;
        for (int i=1; i<=m; i++) {
            scanf("%s%d%d",ch,&p,&v);
            q.push(node(ch[0],p,v,i));
        }
        int cnt=0;
        while (!q.empty()) {
            node tmp = q.front();
            q.pop();
            bool isLast=true;
            if (tmp.dir=='H') {
                for (int i=1; i<=n; i++) {
                    if (ed[tmp.pos][i]==tmp.val||ed[tmp.pos][i]==-1) {
                        continue;
                    }
                    else{
                        isLast=false;
                        break;
                    }
                }
                if (isLast) {
                    for (int i=1; i<=n; i++) {
                        ed[tmp.pos][i]=-1;
                    }
                    ans[cnt++]=tmp.id;
                }
                else
                    q.push(tmp);
            }
            else{
                for (int i=1; i<=n; i++) {
                    if (ed[i][tmp.pos]==tmp.val||ed[i][tmp.pos]==-1) {
                        continue;
                    }
                    else{
                        isLast=false;
                        break;
                    }
                }
                if (isLast) {
                    for (int i=1; i<=n; i++) {
                        ed[i][tmp.pos]=-1;
                    }
                    ans[cnt++]=tmp.id;
                }
                else
                    q.push(tmp);
            }
        }
//        for (int i=0; i<cnt; i++) {
//            printf("%d%c",ans[i],i==cnt-1?'\n':' ');
//        }
        for (int i=cnt-1; i>=0; i--) {
            printf("%d%c",ans[i],i==0?'\n':' ');
        }
    }
    return 0;
}
