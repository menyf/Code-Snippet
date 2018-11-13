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
    int a[105],n,m,pos,val;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        Memset(a, -1);
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&pos,&val);
            a[pos]=val;
        }
        if (a[1]==-1) {
            a[1]=100;
        }
        if (a[2]==-1) {
            a[2]=a[1];
        }
        
        int tmp=0;
        for (int i=n; i>=1; i--) {
            if (a[i]!=-1) {
                tmp=a[i];
            }
            else{
                a[i]=tmp;
            }
        }
        int sum=0,fz=a[1]+a[2];
        for (int i=1; i<=n; i++) {
            sum+=a[i];
        }
        int gcd=__gcd(sum,fz);
        cout<<fz/gcd<<"/"<<sum/gcd<<endl;
    }
}
