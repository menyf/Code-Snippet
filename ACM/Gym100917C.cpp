// Wrote by MenYifan on 2016-03-21 20:33:50
// Exe.Time 31ms Exe.Memory 2176K
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1e9
#define MIN 1e-8
#define LL long long
#define mys 20000 //23170
#define debug2 puts("****")
#define blank puts("")
#define pf printf
#define sf scanf
#define mem(a,b) memset(a, b, sizeof(a))
#define memc(a) memset(a, '\0', sizeof(a))
#define debug(x) (cout<<"--- "<<(x)<<" ---"<<endl)
long long po(long long k,long long q){
    long long  ans = 1;
    for(int i=1;i<=q;i++) {
        ans*=k;
    }
    return ans;
}

long long fun(long long k,long long q)
{
    return (po(k,q)-1)/(k-1);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long  n;
    while(cin>>n)
    {
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        long long ans1=0;
        for(long long i=1;i<n;i++){
            if(n%i==0){
//            cout<<"??="<<i<<endl;
            ans1++;
            }
        }
        long long ans=0;
        for(long long k=2;k<n;k++){
            for(long long q=2;q<=17&&fun(k,q)<=n;q++){
                long long tmp=fun(k,q);
                if(n%tmp==0){
                ans++;
//                cout<<"n tmp="<<n<<" "<<tmp<<endl;;
//                cout<<"k q="<<k<<" "<<q<<endl;
//                cout<<"a1="<<n/tmp<<endl;
                }
            }
        }

        cout<<ans+ans1<<endl;
    }

    return 0;
}