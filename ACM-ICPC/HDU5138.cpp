// Wrote by MenYifan on 2016-08-08 09:35:20
// Exe.Time 0ms Exe.Memory 1568K
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
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=110119;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int a[] = {1 , 2 , 4 ,7,15};
int main(){
    int T, n;
    while (scanf("%d",&n)!=EOF) {
        
        for (int i=4; i>=1; i--) {
            if (n>a[i]) {
                printf("%d ",n-a[i]);
            }
        }
        printf("%d\n",n-1);
    }
}