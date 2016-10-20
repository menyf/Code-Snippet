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
#define pb push_back
#define mp make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : "<<x<<" "<<y<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=10000010+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int prime[maxn],fac[maxn],num[maxn],pcnt;
void Init_Prime(){
    pcnt=0;
    for (int i=2; i<maxn; i++) {
        if (!fac[i]) {
            fac[i]=i;
            num[i]=1;
            prime[pcnt++]=i;
        }
        for (int j=0; j<pcnt&&i*prime[j]<maxn; j++) {
            fac[i*prime[j]]=prime[j];
            if (!i%prime[j]) break;
        }
        num[i]+=num[i-1];
    }
}
int solve(int n,int d){
    int tmp = n / d;
    if (d<maxn) {
        return num[min(tmp, fac[d])];
    }
    for (int i=0; prime[i]<tmp; i++) {
        if (d % prime[i]==0) {
            return i+1;
        }
    }
    return num[tmp];
}
int main(){
    Init_Prime();
    int t,n,d;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&d);
        cout<<solve(n-1,d)<<endl;
    }
    return 0;
}
