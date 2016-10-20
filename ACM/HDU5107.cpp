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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
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
const int maxn=10000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Point{
    int x,y,he;
}p[30000+5];
bool cmp(Point a,Point b){
    return a.he<b.he;
}
int main(){
    int n,k,x,y,cnt,z;
    while (scanf("%d%d",&n,&k)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].he);
        }
        sort(p, p+n, cmp);
        for (int i=0; i<k; i++) {
            scanf("%d%d%d",&x,&y,&z);
            cnt=0;
            int ans=-1;
            for (int j=0; j<n; j++) {
                if (p[j].x<=x&&p[j].y<=y) {
                    cnt++;
                    if (cnt==z) {
                        ans=p[j].he;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}

