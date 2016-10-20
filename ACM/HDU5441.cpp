// Wrote by MenYifan on 2016-08-25 21:18:17
// Exe.Time 951ms Exe.Memory 3004K
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<iostream>
using namespace std;
int father[50002];
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
int num[50002];
int find(int x)
{
if(father[x]!=x)
father[x]=find(father[x]);
return father[x];

};
struct query
{
    int num;
    int many;
    long long  ans;
}node [5010];

struct edge
{
    int v,u;
    int val;
}e[200010];
bool cmp1(edge x,edge y)
{
    return x.val<y.val;
}

bool cmp2(query x,query y)
{
    return x.many <y.many;
}
bool cmp3(query x ,query y)
{
    return x.num<y.num;
}

int main ()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,q;
        //int maxx=0;
        scanf("%d%d%d",&n,&m,&q);
        for (int i=0;i<=n;i++)
        {
            father[i]=i;
            num[i]=1;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].val);
           // maxx=max(maxx,e[i].val);
        }
        sort (e,e+m,cmp1);
        for (int i=0;i<q;i++)
        {
            scanf("%d",&node[i].many);

            node[i].num=i;
            node[i].ans=0;
        }
        sort(node,node+q,cmp2);
        int be=0;
        for (int i=0;i<q;i++)
        {
            while(e[be].val<=node[i].many&&be<m)
            {
                e[be].v=find(e[be].v);
                e[be].u=find(e[be].u);
                if(e[be].u!=e[be].v)
                {
                    num[e[be].v]+=num[father[e[be].u]];
                    father[e[be].u]=e[be].v;

                }
                be++;
            }
            if(be>=m&&node[i-1].many>=e[m-1].val)
            {
                node[i].ans=node[i-1].ans;//cout<<'a';
                continue;
            }
            for (int j=1;j<=n;j++)
            {
                //cout <<father[j]<<' '<<j<<' '<<num[j]<<endl;
                if(father[j]==j)
                {
                    node[i].ans+=(long long )num[j]*(long long )(num[j]-1);
                }
            }//cout <<endl;
        }
        sort (node ,node+q,cmp3);
        for (int i=0;i<q;i++)
        {
            printf("%I64d\n",node[i].ans);
        }
    }
}