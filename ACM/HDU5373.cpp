// Wrote by MenYifan on 2016-04-20 20:04:09
// Exe.Time 1138ms Exe.Memory 1572K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char s[100];
int main()
{

    int n=1,t;
    while(scanf("%s%d",s,&t))
    {

        if(s[0]=='-'&&t==-1)
            break;
        printf("Case #%d: ",n++);
        int odd=0,ev=0,sum=0;
        int len=strlen(s);
        int flag=0;//0 ev; 1 odd

        for(int i=0; i<len; i++)
        {
            int tmp;
            tmp=s[i]-'0';
            sum+=tmp;
            if(flag) odd+=tmp;
            else ev+=tmp;
            flag^=1;
        }

        char str[40];

        for(int i=0; i<t; i++)
        {
            int id=0,tt=sum;
            while(sum!=0)
            {
                str[id++]=sum%10+'0';
                sum/=10;
            }
            str[id]='\0';
            sum=tt;
            for(int j = id-1;j>=0;j--) {
                int tmp;
                tmp=str[j]-'0';
                if(flag)odd+=tmp;
                else ev+=tmp;
                flag^=1;
                sum+=tmp;
            }
        }

        if(abs(odd-ev)%11)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
