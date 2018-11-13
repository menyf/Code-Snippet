// Wrote by MenYifan on 2015-11-01 20:24:42
// Exe.Time 142ms Exe.Memory 0K
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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
bool cmp(string s1,string s2){
    return s1+s2>s2+s1;
}
int main(){
    string s[55];
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++){
            cout<<s[i];
        }
        cout<<endl;
    }
}
