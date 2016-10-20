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
vector<int>v[45][12][12];
bool cando[45][12];//cando[n][m]表示n,m组合能否成功
int status[45];
int n,m,path[45];
bool ok;
void dfs(int cnt,int pos,int left,int step){
    if (ok)
        return;
    //第cnt个人已经分到了ave块
    if (left==0) {
        for (int i=1; i<=step; i++) {
            v[n][m][cnt].push_back(path[i]);
        }
        ok=true;
        return;
    }
    for (int i=pos; i>=1; i--) {
        if (!status[i]&&left>=i) {
            status[i]=1;
            path[++step]=i;
            dfs(cnt, i-1, left-i, step);
            if (ok)
                return;
            status[i]=0;
        }
    }
}
void prep(){
    int ub,total,ave;
    Memset(cando, false);
    for (int i=1; i<=40; i++) {
        ub=(i+1)/2;//由(n+1)*n/(2*m)>=n推导得到, ub为可取到的m的最大值
        total=i*(i+1)/2;
        for (int j=1; j<=ub; j++) {
            if (total%j==0) {
                cando[i][j]=true;
                ave=total/j;
                n=i,m=j;
                memset(status, 0, sizeof(status));
                for (int k=1; k<=m; k++) {
                    ok=false;
                    dfs(k,n,ave,0);
                }
            }
        }
    }
}
int main(){
    prep();
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        ll nn=(ll)n,mm=(ll)m;
        ll total=(1+nn)*nn/2;
        ll ave=total/mm;
        if (total%mm||ave<nn) {
            puts("NO");
            continue;
        }
        puts("YES");
        int dd=0;//基础解
        
        for (; ; dd++) {
            if (cando[dd][m]&&(n-dd)%(2*m)==0) {
                break;
            }
        }
        int tt=(n-dd)/2;//构造次数
        int ll=dd+1,rr=n;
        for (int i=1; i<=m; i++) {
            int sz=v[dd][m][i].size();
            printf("%d",tt/m*2+sz);
            for (int kk=0; kk<sz; kk++) {
                printf(" %d",v[dd][m][i][kk]);
            }
            for (int j=0; j<tt/m; j++,ll++,rr--) {
                printf(" %d %d",ll,rr);
            }
            puts("");
        }
    }
}
