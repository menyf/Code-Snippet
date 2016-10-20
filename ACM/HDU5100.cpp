// Wrote by MenYifan on 2016-08-01 10:30:39
// Exe.Time 15ms Exe.Memory 1588K
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int MAXN=1000;
int main(){
    int T,n,k;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        if (k>n) {
            cout<<0<<endl;
        }
        else {
            int tmp = n%k;
            tmp = min(tmp, k-tmp);
            cout<<n*n-tmp*tmp<<endl;
        }
    }
    return 0;
}