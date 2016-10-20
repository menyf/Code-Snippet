// Wrote by MenYifan on 2016-05-04 17:08:52
// Exe.Time 0ms Exe.Memory 0K
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
int main(){
    int n,T,kase=1,m1,m2;
    while (scanf("%d",&n)!=EOF&&n) {
        scanf("%d",&T);
        int t[220]={},f[220]={},e[220]={},dp[220][55]={};
        for (int i=1; i<n; i++) {
            scanf("%d",&t[i]);
        }
        scanf("%d",&m1);
        for (int i=1; i<=m1; i++) {
            scanf("%d",&f[i]);
        }
        scanf("%d",&m2);
        for (int i=1; i<=m2; i++) {
            scanf("%d",&e[i]);
        }
        int haveTrain[220][55][2]={};
        for (int i=1; i<=m1; i++) {
            int tmp=f[i];
            haveTrain[tmp][1][0]=1;
            for (int j=1; j<n; j++) {
                tmp+=t[j];
                if (tmp<=T) {
                    haveTrain[tmp][j+1][0]=1;
                }
                else
                    break;
            }
        }
        for (int i=1; i<=m2; i++) {
            int tmp=e[i];
            haveTrain[tmp][n][1]=1;
            for (int j=n-1; j>0; j--) {
                tmp+=t[j];
                if (tmp<=T) {
                    haveTrain[tmp][j][1]=1;
                }
                else
                    break;
            }
        }
        for (int i=1; i<=n; i++) {
            dp[T][i]=INF;
        }
        dp[T][n]=0;
        
        for (int i=T-1; i>=0; i--) {
            for (int j=1; j<=n; j++) {
                dp[i][j]=dp[i+1][j]+1;
                if (j<n&&haveTrain[i][j][0]&&i+t[j]<=T) {
                    dp[i][j]=min(dp[i][j], dp[i+t[j]][j+1]);
                }
                if (j>1&&haveTrain[i][j][1]&&i+t[j-1]<=T) {
                    dp[i][j]=min(dp[i][j], dp[i+t[j-1]][j-1]);
                }
            }
        }
        cout<<"Case Number "<<kase++<<": ";
        if (dp[0][1]>=INF)
            cout<<"impossible\n";
        else
            cout<<dp[0][1]<<endl;
    }
}

/*
 
 4
 55
 5 10 15
 4
 0 5 10 20
 4
 0 5 10 15
 
 4
 18
 123
 5
 0 3 6 10 12
 6
 0 3 5 7 12 15
 
 2
 30
 20
 1
 20
 7
 1 3 5 7 11 13 17 0
*/