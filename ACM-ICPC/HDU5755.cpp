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
const int maxn=1000+5;
const int mod=3;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[maxn][maxn] = {0}, x[maxn] = {0},mp[maxn];
int n;
void Gauss(int equ, int var) {
    int row, max_r, col;
    // print();
    for(row = 0, col = 0; col < var && row < equ; col++, row++) {
        max_r = row;
        for(int i = row + 1; i < equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col])) {
                max_r = i;
            }
        }
        if(!a[max_r][col]) {
            row--;
            continue;
        }
        if(row != max_r) {
            for(int j = 0; j <= var; j++) {
                swap(a[row][j], a[max_r][j]);
            }
        }
        for(int i = row + 1; i < equ; i++) {
            if(a[i][col]) {
                int lcm = a[i][col] / __gcd(a[i][col], a[row][col]) * a[row][col];
                int t1 = lcm / a[i][col];
                int t2 = lcm / a[row][col];
                for(int j = col; j <= var; j++) {
                    a[i][j] = ((a[i][j] * t1 - a[row][j] * t2) % 3 + 3) % 3;
                }
            }
        }
    }
    // print();
    // for(int i = row; i < equ; i++)
    //     if(a[i][var]) continue;
    for(int i = var - 1; i >= 0; i--) {
        x[i] = a[i][var];
        for(int j = i + 1; j < var; j++) {
            //
            x[i] = ((x[i] - a[i][j] * x[j]) % 3 + 3) % 3;
        }
        //mod 3下的逆元就是其本身
        x[i] = a[i][i] * x[i] % 3;
        // printf("x[%d] = %d\n", i, x[i]);
        
    }
}
int main(){
    int t,N,M;
    scanf("%d",&t);
    while (t--) {
        Memset(a,0);
        scanf("%d%d",&N,&M);
        n=N*M;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                scanf("%d",&mp[i*M+j]);
            }
        }
        for (int i=0; i<n; i++) {
            a[i][n]=(3-mp[i])%3;
            a[i][i]=2;
            int l = i-1;
            int r = i+1;
            int u = i-M;
            int d = i+M;
            if (l>=0&&l<n&&i%M!=0) {
                a[i][l]=1;
            }
            if (r>=0&&r<n&&i%M!=M-1) {
                a[i][r]=1;
            }
            if (u>=0&&u<n) {
                a[i][u]=1;
            }
            if (d>=0&&d<n) {
                a[i][d]=1;
            }
        }
        Gauss(n,n);
        vector<int>v;
        for (int i=0; i<n; i++) {
            while (x[i]!=0) {
                v.PB(i);
                x[i]--;
            }
        }
        int sz =  v.size();
        cout<<sz<<endl;
        for (int i=0; i<sz; i++) {
            printf("%d %d\n",v[i]/M+1,v[i]%M+1);
        }
    }
}
