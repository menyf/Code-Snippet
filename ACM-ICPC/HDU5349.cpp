// Wrote by MenYifan on 2016-04-06 18:31:50
// Exe.Time 1060ms Exe.Memory 1732K
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
int main(){
    multiset<int>st;
    int n,op,va;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&op);
        if (op==1) {
            scanf("%d",&va);
            st.insert(va);
        }
        else if (op==2)
        {
            if(!st.empty()){
            multiset<int>::iterator it=st.begin();
            st.erase(*it);}
        }
        else if (op==3)
        {
            if(!st.empty()){
            multiset<int>::iterator it=st.end();
            it--;
            printf("%d\n",*it);}
            else printf("0\n");
        }
    }
}