// Wrote by MenYifan on 2015-04-10 19:26:47
// Exe.Time 15ms Exe.Memory 1580K
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int f[1001];
int c[1001];
int w[1001];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int N,V;
        scanf(" %d %d",&N,&V);
        memset(f,0,sizeof(f));
        for (int i=1; i <= N; ++i)
        {
            scanf("%d",&w[i]);
        }
        for (int i=1; i<=N; i++) {
            scanf("%d",&c[i]);
        }
        for (int i = 1; i <= N; ++i)
        {
            for (int v = V; v >= c[i]; --v)
            {
                if(f[v] > f[v - c[i]] + w[i])
                {
                    f[v] = f[v];
                }
                else
                {
                    f[v] = f[v - c[i]] + w[i];
                }
            }
        }
        printf("%d\n",f[V]);
    }
    return 0;
}
