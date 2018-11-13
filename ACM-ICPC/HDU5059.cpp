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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char s[105],t[105];
int l, r;
int solve(){
    int c;
    if (sscanf(s, "%d",&c)!=1) {
        return 0;
    }
    sprintf(t, "%d",c);
    if (strcmp(s, t)!=0) {
        return 0;
    }
    if (c>=l&&c<=r) {
        return 1;
    }
    else
        return 0;
}
int main(){
    while (gets(s)) {
        cin>>l>>r;
        getchar();
        if (solve()) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
