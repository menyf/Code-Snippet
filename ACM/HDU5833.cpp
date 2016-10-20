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
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

#define Pmax 2005
ll prime[Pmax]={1};
int pcnt=0;//素数下标1~pcnt-1
int factor[Pmax]={1,1}; //factor[i]表示i的最小质因子
void Init_Prime(){
    pcnt=1;
    for(ll i = 2 ; i < Pmax ; i ++){
        if(!factor[i]) {
            prime[pcnt++]=i;
            factor[i]=i;
        }
        for(ll j = 1 ; j < pcnt && i * prime[j] <  Pmax ; j ++)
        {
            factor[i * prime[j]] = prime[j];
            if( !(i % prime[j] ) )
                break;
        }
    }
    return;
}

const int maxn=305;
int equ,var;//等式数,变量数
int a[maxn][maxn],x[maxn];//矩阵(多一列最终状态),答案
int free_x[maxn],free_num;//自由变元
int Gauss()
{
    int max_r,col,k;
    free_num=0;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(int i=k+1;i<equ;i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col]))
                max_r=i;
        }
        if(a[max_r][col]==0)
        {
            k--;
            free_x[free_num++]=col;
            continue;
        }
        if(max_r!=k)
        {
            for(int j=col;j<var+1;j++)
                swap(a[k][j],a[max_r][j]);
        }
        for(int i=k+1;i<equ;i++)
        {
            if(a[i][col]!=0)
            {
                for(int j=col;j<var+1;j++)
                    a[i][j]^=a[k][j];
            }
        }
    }
    for(int i=k;i<equ;i++)
        if(a[i][col]!=0)
            return -1;
    if(k<var) return var-k;
    for(int i=var-1;i>=0;i--)
    {
        x[i]=a[i][var];
        for(int j=i+1;j<var;j++)
            x[i]^=(a[i][j]&&x[j]);
    }
    return 0;
}
ll bin[305]={1};
int main(){
    for (int i=1; i<=304; i++) {
        bin[i] = bin[i-1]*2 %mod;
    }
    Init_Prime();
    int T,n;
    ll tmp;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++) {
        Memset(a, 0);
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%lld",&tmp);
            for (int j=1; j<pcnt; j++) {
                int cnt = 0;
                while (tmp%prime[j]==0) {
                    cnt++;
                    tmp /= prime[j];
                }
                if (cnt%2) {
                    a[j-1][i]=1;
                }
            }
        }
        var = n;
        equ = 303;
        Gauss();
        int rnk = free_num;
        printf("Case #%d:\n",cas);
        cout<<(bin[rnk]-1+mod)%mod<<endl;
    }
}
