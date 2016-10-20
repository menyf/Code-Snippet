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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100005;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char s[maxn],t[maxn];
bool work(){
    int len1=strlen(s);
    int len2=strlen(t);
    int id1=0,id2=0;
    for(id2=1;id2<len2;id2++)
        if(t[id2]!=t[0])break;//找到第一个字符不连续的地方
    for(id1=0;id1<id2;id1++)     //对于i也应该在前j个字符都连续相同
        if(s[id1]!=t[id1])return 0;

    while (id1<len1) {
        for (; id2<len2; id2++) {
            if (s[id1]==t[id2]) {
                break;
            }
        }
        
        if (id2==len2)
            return false;
        id1++,id2++;
    }
    
    return true;
}
int main(){
    int tt;
    scanf("%d",&tt);
    while (tt--) {
        scanf("%s%s",s,t);
        if (work())
            puts("Yes");
        else
            puts("No");
    }
}
