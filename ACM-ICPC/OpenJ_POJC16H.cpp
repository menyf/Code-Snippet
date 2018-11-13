// Wrote by MenYifan on 2016-05-09 21:59:58
// Exe.Time 420ms Exe.Memory 3948K
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
void fre()
{
    freopen("c://test//input.in", "r", stdin);
    freopen("c://test//output.out", "w", stdout);
}
#define MP(x,y) make_pair(x,y)
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
#define debug puts("----------")
//#define INF 0x3f3f3f3f
//#define maxn 105
const long long mod = 1e9+7;
using namespace std;



const int maxn = 4;
const int maxm = 4;
LL  k;
struct Matrix
{
    int n, m;
    LL a[maxn][maxm];
    void clear()
    {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix operator * (const Matrix &b) const   //??????
    {
        Matrix tmp;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) tmp.a[i][j] = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (!a[i][j]) continue;
                for (int k = 0; k < 3; k++)
                    tmp.a[i][k] = tmp.a[i][k] + a[i][j] * b.a[j][k]%mod, tmp.a[i][k] %= mod;
            }
        
        return tmp;
    }
    void Copy(const Matrix &b)
    {
        for (int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) a[i][j] = b.a[i][j];
    }
    void unit(int sz)
    {
        n = m = sz;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) a[i][j] = 0;
            a[i][i] = 1;
        }
    }
} num[20005];
Matrix B;
Matrix Matrix_pow(Matrix A, LL k)   //?????
{
    Matrix res;
    res.clear();
    res.n = res.m = 3;
    for (int i = 0; i < 3; i++) res.a[i][i] = 1;
    while(k)
    {
        if (k & 1) res.Copy(A * res);
        k >>= 1;
        A.Copy(A * A);
    }
    return res;
}

Matrix get(LL u,LL d,LL l,LL r)
{
    Matrix mat;
    LL a = (u + d + l + r) % mod;
    mat.a[0][0] = 1+a , mat.a[0][1] = 0 , mat.a[0][2] = r - l;
    mat.a[1][0] = 0, mat.a[1][1] = 1 + a , mat.a[1][2] = u - d;
    mat.a[2][0] = 0 , mat.a[2][1] = 0 , mat.a[2][2] =1 + a;
    return mat;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        
        LL n,m,x,y;
        LL u,d,l,r;
        num[0].unit(3);
        //        scanf("%I64d%I64d%I64d%I64d",&n,&m,&x,&y);
        cin >> n >> m >> x >> y;
        B.a[0][0] = (x % mod + mod) % mod;
        B.a[1][0] = (y % mod + mod) % mod;
        B.a[2][0] = 1;
        for(int i = 1 ; i <= m ; i++)
        {
            //             scanf("%I64d%I64d%I64d%I64d",&u,&d,&l,&r);
            cin >> u>>d>>l>>r;
            num[i] = get(u,d,l,r);
            num[i] = num[i] * num[i-1];
        }
        
        B =  Matrix_pow(num[m],n/m) * B;
        B =  num[n%m] * B;
        
        cout << (B.a[0][0] + B.a[1][0] + mod) % mod << endl;
    }
    return 0;
}