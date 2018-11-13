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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int fcnt=120005;
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,tmp,sum=0;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&tmp);
            if (tmp%8==7) {
                sum^=(tmp+1);
            }
            else if (tmp%8==0){
                sum^=(tmp-1);
            }
            else
                sum^=tmp;
        }
        if (sum==0) {
            puts("Second player wins.");
        }
        else
            puts("First player wins.");
    }
}
