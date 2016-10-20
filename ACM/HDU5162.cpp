// Wrote by MenYifan on 2016-08-17 19:07:00
// Exe.Time 0ms Exe.Memory 1584K
// poj 2987
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
#define debug(x) cout<<"Debug : >>>"<<x<<"<<<"<<endl;
#define debug2(x,y) cout<<"Debug : >>>"<<x<<" , "<<y<<"<<<"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct node{
    int dis;
    int id;
    int rk;
}child[10000];
bool cmp(node x,node y){
    return x.dis > y.dis;
}
bool cmp2(node x,node y){
    return x.id<y.id;
}
int ans[100005];
int main(){
    int T,n,tmp;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            child[i].id = i;
            child[i].dis = 0;
            for (int j=0; j<3; j++) {
                scanf("%d",&tmp);
                child[i].dis = max(child[i].dis, tmp);
            }
            
        }
        sort(child+1, child+1+n, cmp);
        for (int i=1; i<=n; i++) {
            child[i].rk = i;
        }
        sort(child+1, child+1+n, cmp2);
        
        for (int i=1; i<=n; i++) {
//            debug(child[i].id);
            printf("%d%c",child[i].rk,i==n?'\n':' ');
        }
    }
}