// Wrote by MenYifan on 2016-08-15 21:06:03
// Exe.Time 1388ms Exe.Memory 7068K
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
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
double bin[maxn][7];
double c[maxn][7]= {};
int main(){

    for (int i=1; i<maxn; i++) {
        bin[i][1] = i;
        for (int j=2; j<=6; j++) {
            bin[i][j] = bin[i][j-1] * i;
        }
    }

    int n,m,T,cas=1;
    scanf("%d",&T);
    while (T--) {
        double ans = 0;
        scanf("%d%d",&n,&m);
        ans = bin[n][m]-bin[n-1][m];
        ans *= 1.0*(n+1)*n/2;
        
        ans /= bin[n][m];

        printf("Case #%d: %.3f\n",cas++,ans);
    }
}