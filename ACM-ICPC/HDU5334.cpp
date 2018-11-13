// Wrote by MenYifan on 2016-04-03 23:47:14
// Exe.Time 171ms Exe.Memory 1568K
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
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    int n;
    while (~scanf("%d",&n)) {
        if (n<1e5) {
            printf("%d\n",n);
            for (int i=1; i<n; i++) {
                printf("1 ");
            }
            printf("1\n");
        }
        else{
            //(A+C+1)(B+C+1)=n+(1+C)^2-C
            int a=0,b=0,c=0;
            bool flag=false;
            while (!flag) {
                c++;
                int k=n+(1+c)*(1+c)-c,rt=sqrt(n);
                for (int i=rt; i>=c+1; i--) {
                    if (k%i==0) {
                        a=k/i-c-1;
                        b=i-c-1;
                        if (a+b+c<1e5) {
                            flag=true;
                            break;
                        }
                    }
                }
            }
            printf("%d\n",a+b+c);
            for (int i=0; i<a; i++) {
                printf("1 ");
            }
            for (int i=0; i<b; i++) {
                printf("2 ");
            }
            for (int i=0; i<c; i++) {
                printf("3%c",i==c-1?'\n':' ');
            }
        }
    }
    return 0;
}