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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int n;
int a[maxn];
vector<int> x,y;
bool work(int cur){
    int tmp=cur;
    x.clear();
    y.clear();
    if (cur==1) {
        x.push_back(n);
        y.push_back(1);
    }
    if (cur==-1) {
        x.push_back(1);
        y.push_back(n);
    }
    
    for (int i=1; i<n; i++) {
        cur+=a[i];
        
        if (cur>=2||cur<=-2) {
            return false;
        }
        
        if (cur>0) {
            x.push_back(i);
            y.push_back(i+1);
        }
        else if (cur<0){
            x.push_back(i+1);
            y.push_back(i);
        }
    }
    
    if (cur+a[n]!=tmp)
        return false;
    else
        return true;
    
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int mx=-1,mn=INF;
        ll sum=0,ave;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            mx=max(mx, a[i]);
            mn=min(mn, a[i]);
            sum+=a[i];
        }
        
        // 无法整除
        if (sum%n) {
            puts("NO");
            continue;
        }
        
        // 浮动大于2
        ave=sum/n;
        if (abs(ave-mx)>2||abs(ave-mn)>2) {
            puts("NO");
            continue;
        }
        
        //处理一下
        for (int i=1; i<=n; i++) {
            a[i]-=ave;
        }
        
        if (work(0)) {
            puts("YES");
            int sz=x.size();
            printf("%d\n",sz);
            for (int i=0; i<sz; i++) {
                printf("%d %d\n",x[i],y[i]);
            }
        }
        else if (work(-1)){
            puts("YES");
            int sz=x.size();
            printf("%d\n",sz);
            for (int i=0; i<sz; i++) {
                printf("%d %d\n",x[i],y[i]);
            }
        }
        else if (work(1)){
            puts("YES");
            int sz=x.size();
            printf("%d\n",sz);
            for (int i=0; i<sz; i++) {
                printf("%d %d\n",x[i],y[i]);
            }
        }
        else
            puts("NO");
    }
}
