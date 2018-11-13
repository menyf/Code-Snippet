#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000+100;
char s[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
    int x;
    int y;
};
int ans;
int n,m;
queue<node> q;
vector<node> son[maxn*2];
void BFS1()
{
    memset(vis,false,sizeof(vis));
    node p;
    p.x=1;
    p.y=1;
    ans=0;
    vis[1][1]=true;
    while(!q.empty())
        q.pop();
    if(s[1][1]=='0')
    {
        ans=2;
        q.push(p);
    }
    while(!q.empty())
    {
        node p2;
        p=q.front();
        q.pop();
        if(p.x==n&&p.y==m)
        {
            if(s[n][m]=='0')
            {
                ans=n+m;
                vis[n][m]=true;
            }
            break;
        }
        for(int i=0; i<4; i++)
        {
            p2.x=p.x+dir[i][0];
            p2.y=p.y+dir[i][1];
            if(p2.x>0&&p2.x<=n&&p2.y>0&&p2.y<=m&&!vis[p2.x][p2.y]&&s[p2.x][p2.y]=='0')
            {
                vis[p2.x][p2.y]=true;
                if(p2.x+p2.y>ans)
                {
                    ans=p2.x+p2.y;
                }
                q.push(p2);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s[i]+1);
        }
        BFS1();
        if(ans==n+m)
            printf("0\n");
        else
        {
            for(int i=0; i<=n+m; i++)
                son[i].clear();
            int cur=0;//记录前一位0出现的位置
            if(ans==0)//起点为1
                ans=1;
            else
            {
                for(int i=1; i<=n; i++)//找到所有的离(n,m)最近的点。
                {
                    int j=ans-i;
                    if(j>=1&&j<=m&&vis[i][j]&&s[i][j]=='0')
                    {
                        node v;
                        v.x=i;
                        v.y=j;
                        son[ans].push_back(v);
                    }
                }
                cur=ans;
            }
            for(int i=ans+1; i<=n+m; i++)//枚举每一步
            {
                if(cur==0)//前面不存在0
                {
                    for(int j=1; j<=n; j++)
                    {
                        int k=i-j;
                        node v;
                        if(k>=1&&k<=m&&s[j][k]=='0')
                        {
                            v.x=j;
                            v.y=k;
                            son[i].push_back(v);
                            cur=i;
                        }
                    }
                }
                else
                {
                    for(int j=1; j<=n; j++)
                    {
                        int k=i-j;
                        node v;
                        if(k>=1&&k<=m&&s[j][k]=='0')
                        {
                            for(int l=0; l<son[cur].size(); l++)
                            {
                                v=son[cur][l];
                                if(v.x<=j&&v.y<=k&&v.x+v.y>=cur)//判断前面的0是否可达
                                {
                                    node w;
                                    w.x=j;
                                    w.y=k;
                                    son[i].push_back(w);
                                    break;
                                }
                            }
                        }
                    }
                    if(son[i].size()>0)
                        cur=i;
                }
                
            }
            for(int i=ans+1; i<=n+m; i++)
            {
                if(son[i].size()>0)
                    printf("0");
                else
                    printf("1");
            }
            printf("\n");
        }
    }
    return 0;
}

