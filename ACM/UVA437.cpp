// Wrote by MenYifan on 2016-06-26 13:51:22
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
struct block{
    int x,y,z,area,mx,pre;
    block(int xx=0,int yy=0,int zz=0){
        x=xx;
        y=yy;
        z=zz;
        area=x*y; // ??????
        mx=zz;  // ??
        pre=-1; // ????
    }
};
// ????????
bool cmp(block x,block y){
    return x.area<y.area;
}
int dp(int n){
    block a[35*6],record[35*6];
    
    int x,y,z,cnt=0,ans=-1;
    
    for (int i=0; i<n; i++) {
        scanf("%d%d%d",&x,&y,&z);
        a[6*i]=block(x, y, z);
        a[6*i+1]=block(x, z, y);
        a[6*i+2]=block(z, y, x);
        a[6*i+3]=block(y, x, z);
        a[6*i+4]=block(z, x, y);
        a[6*i+5]=block(y, z, x);
    }
    
    sort(a, a+6*n, cmp);
    
    for (int i=0; i<6*n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (a[i].x>a[j].x&&a[i].y>a[j].y) {
                a[i].mx=max(a[j].mx+a[i].z, a[i].mx);
                ans=max(ans, a[i].mx);
            }
        }
    }
    
    return ans;
}
int main(){
    int n,cas=1;
    while (scanf("%d",&n),n) {
        printf("Case %d: maximum height = %d\n",cas++,dp(n));
    }
    return 0;
}