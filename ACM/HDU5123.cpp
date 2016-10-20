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
const int mod=110119;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int vis[105]={};
        int n,tmp;
        cin>>n;
        while (n--) {
            scanf("%d",&tmp);
            vis[tmp]++;
        }
        int mx=-1,pos;
        for (int i=1; i<=100; i++) {
            if (vis[i]>mx) {
                mx =vis[i];
                pos = i;
            }
        }
        printf("%d\n",pos);
    }
}
