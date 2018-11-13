// Wrote by MenYifan on 2016-05-07 19:09:39
// Exe.Time 0ms Exe.Memory 256K
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
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
string fuck(string x){
    x[0]=toupper(x[0]);
    return x;
}
int work(string x,string y){
    string e="earth",w="water",m="metal",f="fire",d="wood";
    if (x==e&&y==m) {
        cout<<fuck(x)<<" generates "<<y<<"."<<endl;
        return 1;
    }
    else if (x==m&&y==w) {
        cout<<fuck(x)<<" generates "<<y<<"."<<endl;
        return 1;
    }
    else if (x==w&&y==d) {
        cout<<fuck(x)<<" generates "<<y<<"."<<endl;
        return 1;
    }
    else if (x==d&&y==f) {
        cout<<fuck(x)<<" generates "<<y<<"."<<endl;
        return 1;
    }
    else if (x==f&&y==e) {
        cout<<fuck(x)<<" generates "<<y<<"."<<endl;
        return 1;
    }
    else if (x==e&&y==w) {
        cout<<fuck(x)<<" overcomes "<<y<<"."<<endl;
        return 1;
    }
    else if (x==w&&y==f) {
        cout<<fuck(x)<<" overcomes "<<y<<"."<<endl;
        return 1;
    }else if (x==f&&y==m) {
        cout<<fuck(x)<<" overcomes "<<y<<"."<<endl;
        return 1;
    }else if (x==m&&y==d) {
        cout<<fuck(x)<<" overcomes "<<y<<"."<<endl;
        return 1;
    }else if (x==d&&y==e) {
        cout<<fuck(x)<<" overcomes "<<y<<"."<<endl;
        return 1;
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        string a,b;
        cin>>a>>b;
        if (!work(a, b)) {
            work(b, a);
        }
    }
    return 0;
}