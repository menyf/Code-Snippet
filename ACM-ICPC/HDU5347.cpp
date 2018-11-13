// Wrote by MenYifan on 2016-04-06 19:12:02
// Exe.Time 0ms Exe.Memory 1572K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
double a[]={0,1312.0,2372.3,520.2,899.5,800.6,1086.5,1402.3,1313.9,1681.0,2080.7,495.8,737.7,577.5,786.5,1011.8,999.6,1251.2,1520.6,1139.9,1350.8,1008.4,1170.4,890,1037};
int getNo(int x){
    switch (x) {
        case 35:
            return 19;
            break;
        case 36:
            return 20;
            break;
        case 53:
            return 21;
            break;
        case 54:
            return 22;
            break;
        case 85:
            return 23;
            break;
        case 86:
            return 24;
            break;
        default:
            break;
    }
}
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x>18) x=getNo(x);
        if(y>18) y=getNo(y);
        if(a[x]<a[y])
            printf("SECOND BIGGER\n");
        else
            printf("FIRST BIGGER\n");

    }


}
