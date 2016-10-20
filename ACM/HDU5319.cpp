// Wrote by MenYifan on 2016-03-24 19:58:41
// Exe.Time 0ms Exe.Memory 1580K
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
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (j == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 1000000+5
#define mod 1000000007
char mp[55][55];
int n,len,ans;
void change(int x,int y,char col)
{
    ans++;
    if (col=='R') {
        while (x>=1&&x<=n&&y>=1&&y<=len) {
            if (mp[x][y]=='G') {
                mp[x][y]='B';
            }
            else if (mp[x][y]=='R'){
                mp[x][y]='.';
            }
            else
                break;
            x++,y++;
        }
    }
    else{
        while (x>=1&&x<=n&&y>=1&&y<=len) {
            if (mp[x][y]=='G') {
                mp[x][y]='R';
            }
            else if (mp[x][y]=='B'){
                mp[x][y]='.';
            }
            else
                break;
            x++,y--;
        }
    }
    
}
void work(){
    ans=0;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%s",mp[i]+1);
    }
    len = strlen(mp[1]+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=len; j++) {
            if (mp[i][j]=='R') {
                change(i, j, 'R');
            }
            else if (mp[i][j]=='B'){
                change(i, j, 'B');
            }
            else if (mp[i][j]=='G'){
                change(i, j, 'R');
                change(i, j, 'B');
            }
        }
    }
    printf("%d\n",ans);
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        work();
    }
    return 0;
}