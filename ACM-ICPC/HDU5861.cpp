// Wrote by MenYifan on 2016-08-18 20:50:16
// Exe.Time 3276ms Exe.Memory 18860K
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
const int maxn=200000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int w[maxn],c[maxn];
vector<int> G[maxn];
map<int, int>mp;
map<int, int>::iterator it;
int n,m,x,y;
int lowbit(int x){
    return x&(-x);
}
void update(int pos,int val){
    while (pos<maxn) {
        c[pos] += val;
        pos += lowbit(pos);
    }
}
int sum(int pos){
    int rt = 0;
    while (pos>0) {
        rt += c[pos];
        pos -= lowbit(pos);
    }
    return rt;
}
int main(){
    
    while (~scanf("%d%d",&n,&m)) {
        memset(c, 0, sizeof(c));
        for (int i=1; i<n; i++) {
            scanf("%d",&w[i]);
            G[i].clear();
        }
        mp.clear();
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&x,&y);
            if (x>y) {
                swap(x, y);
            }
            G[x].push_back(i);
            G[y].push_back(-i);
        }
        for (int i=0; i<G[1].size(); i++) {
            mp[G[1][i]]=1;
        }
        for (int i=2; i<=n; i++) {
            if (!mp.empty()) {
                it = mp.begin(); x = it->first;
                it = mp.end(); y = (--it)->first;
                update(x, w[i-1]);
                update(y+1, -w[i-1]);
            }
            for (int j=0; j<G[i].size(); j++) {
                if (G[i][j]>0) {
                    mp[G[i][j]]=1;
                }
                else{
                    mp.erase(-G[i][j]);
                }
            }
        }
        for (int i=1; i<=m; i++) {
            cout<<sum(i)<<endl;
        }
    }
}