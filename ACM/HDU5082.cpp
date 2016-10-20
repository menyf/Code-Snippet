// Wrote by MenYifan on 2016-07-25 19:04:48
// Exe.Time 0ms Exe.Memory 1580K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    char s1[50],s2[50];
    while (scanf("%s %s",s1,s2)!=EOF) {
        bool flag=false;
        for (int i=0; s1[i]; i++) {
            if (flag) {
                printf("%c",s1[i]);
            }
            if (s1[i]=='_') {
                flag=true;
            }
            
        }
        printf("_small_");
        flag=false;
        for (int i=0; s2[i]; i++) {
            if (flag) {
                printf("%c",s2[i]);
            }
            if (s2[i]=='_') {
                flag=true;
            }
            
        }
        printf("\n");
    }
}