// Wrote by MenYifan on 2016-08-26 19:09:22
// Exe.Time 0ms Exe.Memory 1584K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=1000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Node{
    int f,s,t,diff;
    bool operator < (const Node &x )const{
        if(diff != x.diff) return diff >x.diff;
        else if (s != x.s) return s<x.s;
        else return t < x.t;
    }
    void in (int _t){
        scanf("%d%d",&f,&s);
        t = _t;
        diff = f - s;
    }
}a[maxn];
int main(){
//
//
#ifdef ONLINE_JUDGE
#else
    // freopen("in.txt","r",stdin);
    double t1 = clock();
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i= 0 ;i <n ;i++){
            a[i].in(i);
        }
        sort(a,a+n);
        for(int i = 0;i<n;i++){
            printf("%d%c",a[i].t,i==n-1?'\n':' ');
        }
    }

#ifdef ONLINE_JUDGE
#else   
    printf("Finished, time used: ");
    cerr << (clock()-t1) / CLOCKS_PER_SEC ;
    printf("s\n");
    getchar();
#endif
    return 0;
}