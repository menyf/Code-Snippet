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
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define pii pair<int,int>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char str[100005],s[5005];
int ans[100005];
int len1,len2,t;
int work(int pos){
    int idx=0;
    while (idx<len2) {
        if (str[idx+pos]==s[idx]) {
            idx++;
        }
        else if (idx+1<len2&&str[idx+pos]==s[idx+1]&&str[idx+pos+1]==s[idx]){
            idx+=2;
        }
        else
            return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&t);
    while (t--) {
        Memset(ans, 0);
        scanf("%d%d%s%s",&len1,&len2,str,s);
        for (int i=0; i<=len1-len2; i++) {
            if (str[i]==s[0]||str[i]==s[1]) {
                ans[i]=work(i);
            }
        }
        for (int i=0; i<len1; i++) {
            printf("%d",ans[i]);
        }
        printf("\n");
    }
}
