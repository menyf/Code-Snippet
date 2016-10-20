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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(checker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
map<string, int>mp;
int main(){
    mp.insert(make_pair("Baltimore Bullets",1));
    mp.insert(make_pair("Boston Celtics",17));
    mp.insert(make_pair("Chicago Bulls",6));
    mp.insert(make_pair("Cleveland Cavaliers",1));
    mp.insert(make_pair("Dallas Mavericks",1));
    mp.insert(make_pair("Detroit Pistons",3));
    mp.insert(make_pair("Golden State Warriors",2));
    mp.insert(make_pair("Houston Rockets",2));
    mp.insert(make_pair("L.A. Lakers",11));
    mp.insert(make_pair("Miami Heat",3));
    mp.insert(make_pair("Milwaukee Bucks",1));
    mp.insert(make_pair("Minneapolis Lakers",5));
    mp.insert(make_pair("New York Knicks",2));
    mp.insert(make_pair("Philadelphia 76ers",2));
    mp.insert(make_pair("Philadelphia Warriors",2));
    mp.insert(make_pair("Portland Trail Blazers",1));
    mp.insert(make_pair("Rochester Royals",1));
    mp.insert(make_pair("San Antonio Spurs",5));
    mp.insert(make_pair("Seattle Sonics",1));
    mp.insert(make_pair("St. Louis Hawks",1));
    mp.insert(make_pair("Syracuse Nats",1));
    mp.insert(make_pair("Washington Bullets",1));
    int t,cs=1;
    char s[100];
    scanf("%d",&t);
    getchar();
    while (t--) {    
        gets(s);
        string ss =s ;
        printf("Case #%d: ",cs++);
        cout<<mp[ss]<<endl;
    }
}
