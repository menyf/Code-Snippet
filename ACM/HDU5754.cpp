//别人家的题解：http://blog.csdn.net/qingshui23/article/details/52038740
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
    int T;
    int N,M,type;
    cin>>T;
    while(T--)
    {
        scanf("%d%d%d",&type,&N,&M);
        if(type==1)
        {
            if(N>M) swap(N,M);
            if(N%2==0||M%2==0) puts("B");
            else  puts("G");
        }
        else if(type==2)
        {
            if(N!=M) puts("B");
            else  puts("G");
        }
        else if(type==4)
        {
            if(N>M) swap(N,M);
            N--,M--;
            int tmp = (int)((1.0*sqrt(5.0)+1)/2*(M-N));
            if(tmp == N)
                puts("G");
            else
                puts("B");
        }
        else if(type==3)
        {
            if(N>M) swap(N,M);
            if(N==M&&N%3==1)           puts("G");
            else if((N+1)==M&&M%3==0)  puts("B");
            else                       puts("D");
        }
    }
    return 0;
}
