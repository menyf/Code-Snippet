#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100050;
int main()
{
    int n,b,c;
    int a[105];
    while(scanf("%d%d%d",&n,&b,&c)!=EOF)
    {
        int ans=0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(abs(a[i]-a[j])%b==c)
                    ans+=1;
        
        printf("%d\n",ans);
    }
}

