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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char num[105];
char tmp[30];
int main(){
    while (scanf("%s",num)!=EOF) {
        if (strlen(num)>10||num[0]=='0') {
            puts("TAT");
            continue;
        }
        ll a;
        sscanf(num, "%lld",&a);
        if (a<(1LL<<2)) {
            cout<<1<<endl;
        }
        else if (a<(1LL<<4)) {
            cout<<2<<endl;
        }
        else if (a<(1LL<<8)) {
            cout<<3<<endl;
        }
        else if (a<(1LL<<16)) {
            cout<<4<<endl;
        }
        else if (a<(1LL<<32)) {
            cout<<5<<endl;
        }
        else{
            puts("TAT");
        }
    }
    return 0;
}
