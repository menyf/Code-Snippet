// Wrote by MenYifan on 2016-07-17 10:53:38
// Exe.Time 15ms Exe.Memory 1704K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char str[100005];
int vis[27];
int main()
{
    int t,k;
    cin>>t;
    while (t--) {
        Memset(vis, 0);
        scanf("%s %d",str+1,&k);
        int start=1,end=1,len=strlen(str+1);
        ll ans=0;
        for (int i=1; i<=len; i++,end++) {
            int now = str[i]- 'a' +1;
            vis[now]++;
            if (vis[now]>k) {
                // ????
                while (vis[now]>k) {
                    int tmp =str[start++]- 'a' +1;
                    vis[tmp]--;
                }
                ans+=end-start+1;
            }
            else
                ans+=end-start+1;
        }
        cout<<ans<<endl;
    }
}

/*
10 aaabbbccc 2
*/