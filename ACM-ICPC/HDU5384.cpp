// Wrote by MenYifan on 2016-04-27 22:26:39
// Exe.Time 156ms Exe.Memory 11364K
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
const int maxn=1000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct trie
{
    int next[500010][26],fail[500010],ed[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0; i < 26; i++)
            next[L][i] = -1;
        ed[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        ed[now]++;
    }
    void build()
    {
        queue<int> q;
        fail[root] = root;
        for(int i = 0; i < 26; i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int i = 0; i < 26; i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while(temp != root)
            {
                res += ed[temp];
                temp = fail[temp];
            }
        }
        return res;
    }
    void Debug()
    {
        for(int i = 0; i < L; i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],ed[i]);
            for(int j = 0; j < 26; j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
char buf[1000010];
trie ac;
char ss[100005][10005];
int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ac.init();
        for (int i=0; i<n; i++) {
            scanf("%s",ss[i]);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        for (int i=0; i<n; i++) {
            printf("%d\n",ac.query(ss[i]));
        }
    }
    return 0;
}
