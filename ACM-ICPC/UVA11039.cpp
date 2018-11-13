// Wrote by MenYifan on 2015-11-01 18:19:09
// Exe.Time 36ms Exe.Memory 0K
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
#define maxn 100050
bool cmp(int x,int y){
    return abs(x)>abs(y);
}
int main(){
    int t,n,a[maxn],ans,flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n,cmp);
        if(a[1]>0) flag=1;
        else flag=-1;
        ans=1;
        for(int i=1;i<=n;i++){
            if(a[i]*flag<0){
                flag*=-1;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
