// Wrote by MenYifan on 2016-09-12 19:18:25
// Exe.Time 0ms Exe.Memory 1564K
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
const int maxn=200000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
//int dp1[30][30],dp2[30][30];
//int main(){
//    int a[30];
//    for (int len = 2; len <= 24; len++) {
//        for (int black = 1; black <= 12; black++) {
//            int white = len - black;
//            if (white < 1 || white >12) {
//                continue;
//            }
//            memset(a, 0, sizeof(a));
//            int tmp = black;
//            for (int i = len; tmp>0&&i>=0; i--,tmp--) {
//                a[i] = 1;
//            }
//            int cnt = 0;
//            int tcnt = 0;
//            do {
//                
//                cnt++;
//                for (int i = 2; i<=len; i++) {
//                    if (a[i] == 1 && a[i-1] == 0) {
//                        tcnt ++;
//                    }
//                }
//                if (black == 2 &&white == 3) {
//                    for (int i =1; i<=len; i++) {
//                        printf("%d ",a[i]);
//                    }
//                    printf(" : %d \n",tcnt);
//                }
//                
//            } while (next_permutation(a+1, a+1+len));
//            dp1[black][white] = tcnt;
//            dp2[black][white] = cnt;
//            /*
//             '00011' or S='00101' or S='00110' or S='01001' or S='01010'
//             or S='01100' or S='10001' or S='10010' or S='10100' or S='11000',
//             */
//        }
//    }
//    
//    for (int i = 1; i<=12; i++) {
//        for (int j =1; j<=12; j++) {
//            printf("%d,",dp1[i][j]);
//        }
//    }
//    printf("\n");
//    for (int i=1; i<=12; i++) {
//        for (int j =1; j<=12; j++) {
//            printf("%d,",dp2[i][j]);
//        }
//    }
//    debug2(dp1[2][3], dp2[2][3]);
//    
//}
int dp1[12][12]={1,2,3,4,5,6,7,8,9,10,11,12,2,6,12,20,30,42,56,72,90,110,132,156,3,12,30,60,105,168,252,360,495,660,858,1092,4,20,60,140,280,504,840,1320,1980,2860,4004,5460,5,30,105,280,630,1260,2310,3960,6435,10010,15015,21840,6,42,168,504,1260,2772,5544,10296,18018,30030,48048,74256,7,56,252,840,2310,5544,12012,24024,45045,80080,136136,222768,8,72,360,1320,3960,10296,24024,51480,102960,194480,350064,604656,9,90,495,1980,6435,18018,45045,102960,218790,437580,831402,1511640,10,110,660,2860,10010,30030,80080,194480,437580,923780,1847560,3527160,11,132,858,4004,15015,48048,136136,350064,831402,1847560,3879876,7759752,12,156,1092,5460,21840,74256,222768,604656,1511640,3527160,7759752,16224936};
int dp2[12][12]={2,3,4,5,6,7,8,9,10,11,12,13,3,6,10,15,21,28,36,45,55,66,78,91,4,10,20,35,56,84,120,165,220,286,364,455,5,15,35,70,126,210,330,495,715,1001,1365,1820,6,21,56,126,252,462,792,1287,2002,3003,4368,6188,7,28,84,210,462,924,1716,3003,5005,8008,12376,18564,8,36,120,330,792,1716,3432,6435,11440,19448,31824,50388,9,45,165,495,1287,3003,6435,12870,24310,43758,75582,125970,10,55,220,715,2002,5005,11440,24310,48620,92378,167960,293930,11,66,286,1001,3003,8008,19448,43758,92378,184756,352716,646646,12,78,364,1365,4368,12376,31824,75582,167960,352716,705432,1352078,13,91,455,1820,6188,18564,50388,125970,293930,646646,1352078,2704156};
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int a = dp1[n-1][m-1];
        int b = dp2[n-1][m-1];
        int gcd = __gcd(a,b);
        a /= gcd;
        b /= gcd;
        printf("%d/%d\n",a,b);
    }
}