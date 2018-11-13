// Wrote by MenYifan on 2015-03-08 21:56:36
// Exe.Time 0ms Exe.Memory 1708K
#include<stdio.h>
#include<cstring>
#include "iostream"
using namespace std;
int main()
{
    int  t=0, m;
    cin>>m;
    for (t=0; t<m; t++) {
        char s[100000];
        scanf("%s",s);
        getchar();
        int i,num=1;
        for(i=1;i<=strlen(s);i++)
        {
            if(s[i]==s[i-1]&&i!=0)
            {
                num++;
            }
            else
            {
                if(num==1)
                    cout<<s[i-1];
                else printf("%d%c",num,s[i-1]);
                num=1;
            }
        }
        printf("\n");
    }
    
}