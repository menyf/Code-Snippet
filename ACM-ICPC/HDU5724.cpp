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
#define pb push_back
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("1005.in","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=10+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int sg[1<<20];
void Init(){
    for(int i = 1;i < (1<<20); i++){
        int h[25];
        memset(h, -1, sizeof(h));
        int last = -1;
        for(int j = 0; j < 20; j++){
            if(!((i >> j) & 1))
                last = j;
            if(((i >> j) & 1)){
                if(last != -1){
                    h[sg[(i ^ (1 << j)) ^ (1 << last)]]=1;
                }
            }
        }
        int j=0;
        while(h[j] != -1) j++;
        sg[i]=j;
    }

}
int main(){
    Init();
    int T,n,m,len,tmp;
    scanf("%d", &T);
    while (T--) {
        int sum =0;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&m);
            tmp = 0;
            for (int j=1; j<=m; j++) {
                scanf("%d",&len);
                tmp |= (1<<(20-len));
            }
            sum ^= sg[tmp];
        }
        if (sum)
            puts("YES");
        else
            puts("NO");
    }
}
