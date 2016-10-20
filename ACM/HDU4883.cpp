// Wrote by MenYifan on 2016-03-07 19:40:47
// Exe.Time 483ms Exe.Memory 1624K

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1500
int c[maxn],n;
int node[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        memset(node,0,sizeof(node));
        int n,ans=0,cnt=0;
        cin>>n;
        int h,hh,m,mm,tmp,g;
        for(int i=0;i<n;i++){
            scanf("%d %d:%d %d:%d",&g,&h,&m,&hh,&mm);
            tmp=h*60+m;
            node[tmp]+=g;
            tmp=hh*60+mm;
            node[tmp]-=g;
        }
        int total=0;
        for(int i=0;i<maxn;i++)
        {
            total+=node[i];
            ans=max(total,ans);
        }
        cout<<ans<<endl;
    }
}
