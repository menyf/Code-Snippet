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
#define IN freopen("data_in.txt","r",stdin);
#define OUT freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=10007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=10000+5;
char s[maxn][2];
double xf[maxn];
int main(){
	printf("输入一个行号 : ");
	int id;
	cin>>id;
	printf("总共有多少科？\n");
	int n;
	cin>>n;
	for(int i = 0; i < n ;i++){
		scanf("%s %lf",s[i],&xf[i]);
	}
	for(int i = 0; i < n; i++){
		printf("+LOOKUP(%c%d,{0,60,65,70,75,80,85,90},{0,1,1.5,2,2.5,3,3.5,4})*%.1f",s[i][0],id,xf[i]);
	}
}