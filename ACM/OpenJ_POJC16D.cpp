// Wrote by MenYifan on 2016-05-09 21:03:45
// Exe.Time 50ms Exe.Memory 2100K
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
typedef long long ll;;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
#define inf 9999
#define Vmax 1000005
#define Emax 4000005
typedef long long mytype;
const int SZ=3;
const long long M=1000000007;const int ra=10;
int ten[4]= {1,ra,ra*ra,ra*ra*ra};
int radix=ra*ra*ra*ra;
const int NV=1000;
struct integer
{
    int d[NV];
    integer()
    {
        *this=integer(0);
    }
    integer(int x)
    {
        for (int i=0; i<NV; i++) d[i]=0;
        if (!x) d[0]=1;
        while(x)
        {
            d[++d[0]]=x%radix;
            x/=radix;
        }
    }
    integer(long long x)
    {
        for (int i=0; i<NV; i++) d[i]=0;
        if (!x) d[0]=1;
        while(x)
        {
            d[++d[0]]=x%radix;
            x/=radix;
        }
    }
    integer(const char s[])
    {
        int len=strlen(s),i,j,k;
        d[0]=(len-1)/4+1;
        for (i=1; i<NV; i++) d[i]=0;
        for (i=len-1; i>=0; i--)
        {
            j=(len-i-1)/4+1;
            k=(len-i-1)%4;
            d[j]+=ten[k]*(s[i]-'0');
        }
        while(d[0]>1&&d[d[0]]==0) d[0]--;
    }
    string tostring()
    {
        string s;
        int i,j,temp;
        for (i=3; i>=1; i--) if (d[d[0]]>=ten[i]) break;
        temp=d[d[0]];
        for (j=i; j>=0; j--)
        {
            s+=(char) (temp/ten[j]+'0');
            temp%=ten[j];
        }
        for (i=d[0]-1; i>0; i--)
        {
            temp=d[i];
            for (j=3; j>=0; j--)
            {
                s+=(char) (temp/ten[j]+'0');
                temp%=ten[j];
            }
        }
        return s;
    }
    void output()
    {
        int k=d[0];
        printf("%d",d[k--]);
        while(k) printf("%04d",d[k--]);
        putchar('\n');
    }
} d,mid1[15];
bool operator <(const integer &a,const integer &b)
{
    if (a.d[0]!=b.d[0]) return a.d[0]<b.d[0];
    for (int i=a.d[0]; i>0; i--)
        if (a.d[i]!=b.d[i])
            return a.d[i]<b.d[i];
    return 0;
}
integer operator +(const integer &a,const integer &b)
{
    integer c;
    c.d[0]=max(a.d[0],b.d[0]);
    int i,x=0;
    for (i=1; i<=c.d[0]; i++)
    {
        x+=a.d[i]+b.d[i];
        c.d[i]=x%radix;
        x/=radix;
    }
    while(x)
    {
        c.d[++c.d[0]]=x%radix;
        x/=radix;
    }
    return c;
}
integer operator -(const integer &a,const integer &b)
{
    integer c;
    c.d[0]=a.d[0];
    int i,x=0;
    for (i=1; i<=c.d[0]; i++)
    {
        x+=radix+a.d[i]-b.d[i];
        c.d[i]=x%radix;
        x=x/radix-1;
    }
    while(c.d[0]>1&&c.d[c.d[0]]==0) c.d[0]--;
    return c;
}
integer operator *(const integer &a,const integer &b)
{
    integer c;
    c.d[0]=a.d[0]+b.d[0];
    int i,j,x=0;
    for (i=1; i<=a.d[0]; i++)
    {
        x=0;
        for (j=1; j<=b.d[0]; j++)
        {
            x=a.d[i]*b.d[j]+x+c.d[i+j-1];
            c.d[i+j-1]=x%radix;
            x/=radix;
        }
        c.d[i+b.d[0]]=x;
    }
    while(c.d[0]>1&&c.d[c.d[0]]==0) c.d[0]--;
    return c;
}
integer operator *(const integer &a,const long long &k)
{
    integer c;
    c.d[0]=a.d[0];
    int i;
    long long x=0;
    for (i=1; i<=a.d[0]; i++)
    {
        x+=a.d[i]*k;
        c.d[i]=x%radix;
        x/=radix;
    }
    while(x>0)
    {
        c.d[++c.d[0]]=x%radix;
        x/=radix;
    }
    while(c.d[0]>1&&c.d[c.d[0]]==0) c.d[0]--;
    return c;
}
long long rem;
integer operator /(const integer &a,const long long &k)
{
    integer c;
    c.d[0]=a.d[0];
    long long x=0;
    for (int i=a.d[0]; i>=1; i--)
    {
        x+=a.d[i];
        c.d[i]=x/k;
        x%=k;
        rem=x;
        x*=radix;
    }
    while(c.d[0]>1&&c.d[c.d[0]]==0) c.d[0]--;
    return c;
}
bool smaller(const integer &a,const integer &b,int delta)
{
    if (a.d[0]+delta!=b.d[0]) return a.d[0]+delta<b.d[0];
    for (int i=a.d[0]; i>0; i--)
        if (a.d[i]!=b.d[i+delta])
            return a.d[i]<b.d[i+delta];
    return 1;
}
void Minus(integer &a,const integer &b,int delta)
{
    int i,x=0;
    for (i=1; i<=a.d[0]-delta; i++)
    {
        x+=radix+a.d[i+delta]-b.d[i];
        a.d[i+delta]=x%radix;
        x=x/radix-1;
    }
    while(a.d[0]>1&&a.d[a.d[0]]==0) a.d[0]--;
}
integer operator /(const integer &a,const integer &b)
{
    integer c;
    d=a;
    int i,j,temp;
    mid1[0]=b;
    for (i=1; i<=13; i++) mid1[i]=mid1[i-1]*2;
    for (i=a.d[0]-b.d[0]; i>=0; i--)
    {
        temp=8192;
        for (j=13; j>=0; j--)
        {
            if (smaller(mid1[j],d,i))
            {
                Minus(d,mid1[j],i);
                c.d[i+1]+=temp;
            }
            temp/=2;
        }
    }
    c.d[0]=max(1,a.d[0]-b.d[0]+1);
    while(c.d[0]>1&&c.d[c.d[0]]==0) c.d[0]--;
    return c;
}
bool operator ==(const integer &a,const integer &b)
{
    if (a.d[0]!=b.d[0]) return 0;
    for (int i=1; i<=a.d[0]; i++)
        if (a.d[i]!=b.d[i])
            return 0;
    return 1;
}
void init(int b) ///????????<=10??
{
    for (int i=1; i<=3; i++)
        ten[i]=ten[i-1]*b;
    radix=b*b*b*b;
}

integer odd[202];
integer even[202];
void prep(){
    odd[1]=integer(1);
    odd[2]=integer(2);
    odd[3]=integer(3);
    even[1]=integer(1);
    even[2]=integer(2);
    even[3]=integer(6);
    even[4]=integer(9);
    for (int i=5; i<=200; i++)
        if (i%2) {
            odd[i-1]=odd[i-2]*4;
            odd[i]=odd[i-2]*6;
        }
        else{
            even[i-1]=even[i-2]*4;
            even[i]=even[i-2]*6;
        }
}
int main(){
    prep();
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (n==2) {
            cout<<-1<<endl;
            continue;
        }

        if (n%2)
            for (int i=1; i<=n; i++)
                cout<<odd[i].tostring()<<endl;
        else
            for (int i=1; i<=n; i++)
                cout<<even[i].tostring()<<endl;
    }
    return 0;
}
