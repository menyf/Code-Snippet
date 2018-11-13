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
void work(int n){
    int tmp;
    set<int> st1,st2;
    for (int i=1; i<=n; i++) {
        cin>>tmp;
        st1.insert(tmp);
    }
    for (int i=1; i<=n; i++) {
        cin>>tmp;
        st2.insert(tmp);
    }
    if (st1.size()!=st2.size()) {
        cout<<"NO"<<endl;
        return;
    }
    set<int>::iterator it1=st1.begin(),it2=st2.begin();
    for (; it1!=st1.end(); it1++,it2++) {
        if (*it1!=*it2) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}
int main(){
    int n;
    while (cin>>n) {
        work(n);
    }
}
