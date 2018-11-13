// Wrote by MenYifan on 2016-07-30 11:13:20
// Exe.Time 15ms Exe.Memory 1592K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int MAXN=40+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
//?equ????var???????????equ,???var+1,???0?var
int equ,var;
int a[MAXN][MAXN]; //????
int x[MAXN]; //??
int free_x[MAXN];//??????????????????????
int free_num;//???????
//????-1??????0???????????????
int Gauss()
{
    int max_r,col,k;
    free_num = 0;
    for(k = 0, col = 0 ; k < equ && col < var ; k++, col++)
    {
        max_r = k;
        for(int i = k+1;i < equ;i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;//???????
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        for(int i = k+1;i < equ;i++)
        {
            if(a[i][col] != 0)
            {
                for(int j = col;j < var+1;j++)
                    a[i][j] ^= a[k][j];
            }
        }
    }
    for(int i = k;i < equ;i++)//????????????????? ?? ?????????????????????
        if(a[i][col] != 0)//??????1??????????????0
            return -1;//??
    if(k < var) return var-k;//??????
    //??????
    for(int i = var-1; i >= 0;i--)
    {
        x[i] = a[i][var];
        for(int j = i+1;j < var;j++)
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}
int main(){
    int t, n;
    ll tmp;
    scanf("%d",&t);
    while (t--) {
        memset(a, 0, sizeof(a));
        scanf("%d",&n);
        if (n>40) {
            while (n--) {
                scanf("%*lld");
            }
            printf("Yes\n");
        }
        else
        {
            for (int i=0; i<n; i++) {
                scanf("%lld",&tmp);
                for (int j=0; j<MAXN; j++) {
                    if (tmp>>j&1) {
                        a[j][i]=1;
                    }
                }
            }
            equ = MAXN;
            var = n;
            if (Gauss()>0) {
                printf("Yes\n");
            }
            else
                printf("No\n");
        }
        
    }
}