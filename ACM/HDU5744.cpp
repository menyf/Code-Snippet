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
#define mp make_pair
#define pb push_back
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int cnt=0;
        int total=0,tmp;
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&tmp);
            if (tmp%2) {
                total+=tmp-1;
                cnt++;
            }
            else{
                total+=tmp;
            }
        }
        
        if (cnt==0) {
            cout<<total<<endl;
        }
        else{
            tmp=total/cnt;
            if (tmp%2) {
                tmp--;
            }
            cout<<1+tmp<<endl;
        }
    }
}
