#include <set>
#include <map>
#include <list>
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
#define fre() freopen("data_in.txt","r",stdin); \
              freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=1000000+10;
int a[maxn],b[maxn],f[maxn];
int n,m,p;
void getFail(int *P, int *f){
    int lenP = m;
    f[0] = 0; f[1] = 0; //递推边界初值
    for (int i=1; i<lenP; i++) {
        int j = f[i];
        while (j&&P[i]!=P[j]) {
            j = f[j];
        }
        f[i+1] = (P[i]==P[j]?j+1:0);
    }
}
int KMP(int *T, int *P, int *f){
    int lenT = n;
    int lenP = m;
    getFail(P, f);
    int ans = 0;
    for (int k = 0 ; k < p ; k++) {
        int j = 0;  //当前结点的编号，初始为0号始点
        for (int i = k; i<lenT; i += p) { //文本串当前指针
            while (j && P[j]!=T[i])    //顺着失败边走，直到可以匹配
                j = f[j];
            if (P[j] == T[i]) j++;
            if (j==lenP) ans++;
        }
    }
    return ans;
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&p);
        memset(b, -1, sizeof(b));
        for (int i = 0 ; i < n ; i++) 
            scanf("%d",&a[i]);
        for (int i = 0 ; i < m ; i++) 
            scanf("%d",&b[i]);
        printf("Case #%d: %d\n",cas++,KMP(a, b, f));
    }    
}
