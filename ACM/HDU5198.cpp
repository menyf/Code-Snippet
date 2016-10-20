// Wrote by MenYifan on 2016-09-14 19:08:04
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char name[20];
int main(){
    while (scanf("%s",name+1)!=EOF) {
        int len = strlen(name+1);
        if (len % 3) {
            puts("NO");
        }
        else{
            bool flag = true;
            char a = name[1],b = name [len/3 + 1],c = name[len];
            for (int i = 1; i<=len/3; i++) {
                if (name[i] != a) {
                    flag = false;
//                    debug2(1, i);
                }
            }
            for (int i = 1,j=len/3+1; i<=len/3; i++,j++) {
                if (name[j]!=b) {
                    flag = false;
//                    debug2(2, i);
                }
            }
            for (int i =1, j = len / 3 * 2 + 1; i<=len/3; i++,j++) {
                if (name[j]!=c) {
                    flag = false;
//                    debug2(3, i);
                }
            }
            if (flag && a!=b && a!=c && b!=c) {
                puts("YES");
            }
            else
                puts("NO");
        }
    }
}