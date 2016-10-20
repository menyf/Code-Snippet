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
    int t,h1,h2,m1,m2,s1,s2,h,m,s;
    cin>>t;
    while (t--) {
        h=s=m=0;
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        s=s1+s2;
        if (s>=60) {
            s=s%60;
            m=1;
        }
        m+=m1+m2;
        if (m>=60) {
            m=m%60;
            h=1;
        }
        h+=h1+h2;
        cout<<h<<" "<<m<<" "<<s<<endl;
    }
}
