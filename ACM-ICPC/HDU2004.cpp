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
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    int s;
    while (scanf("%d",&s)!=EOF) {
        if (s>100) {
            printf("Score is error!\n");
        }
        else if (s>89){
            puts("A");
        }
        else if (s>79){
            puts("B");
        }
        else if (s>69){
            puts("C");
        }
        else if (s>59){
            puts("D");
        }
        else if (s>-1){
            puts("E");
        }
        else
            puts("Score is error!");
    }
}
