// Wrote by MenYifan on 2016-05-09 18:31:00
// Exe.Time 0ms Exe.Memory 512K
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
typedef long long ll;;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
double l[maxn],r[maxn];
char s[25];
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        cin>>n;
        bool flag=true;
        for (int i=0; i<n; i++) {
            scanf("%s",s);
            if (i%2&&s[0]=='#')
                flag=false;
            else if (!i%2&&s[0]!='#')
                flag=false;
        }
        if (n%2==0) {
            puts("No");
        }
        else{
            if (flag) {
                puts("Yes");
            }
            else
                puts("No");
        }
    }
}