// Wrote by MenYifan on 2016-07-17 09:47:41
// Exe.Time 62ms Exe.Memory 1592K
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
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    int n;
    int a[105];
    while (cin>>n) {
        for (int i=1; i<=n; i++) {
            cin>>a[i];
        }
        sort(a+1, a+1+n, cmp);
        for (int i=n; i>=1; i--) {
            if (a[i]%2==1) {
                a[n+1]=a[i];
                a[i]=-1;
                break;
            }
            if (i==1) {
                n=-1;
                cout<<n;
            }
        }
        bool flag=true;
        for (int i=1; i<=n+1; i++) {
            if (a[i]!=-1) {
                if (flag) {
                    if (a[i]==0) {
                        cout<<-1;
                        break;
                    }
                }
                cout<<a[i];
                flag=false;
            }
        }
        cout<<endl;
    }
}