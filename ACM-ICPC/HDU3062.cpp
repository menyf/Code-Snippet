#include <set>
#include <map>
#include <list>
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
#define fre() freopen("data_in.txt","r",stdin); \
			  freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
struct TwoSAT
{
	int n;//原始图的节点数(未翻倍)
	vector<int> G[maxn*2];//G[i]==j表示如果mark[i]=true,那么mark[j]也要=true
	bool mark[maxn*2];//标记
	int S[maxn*2],c;//S和c用来记录一次dfs遍历的所有节点编号

	void init(int n)
	{
		this->n=n;
		for(int i=0;i<2*n;i++) G[i].clear();
		memset(mark,0,sizeof(mark));
	}

	//加入(x,xval)或(y,yval)条件
	//xval=0表示假，yval=1表示真
	void add_clause(int x,int xval,int y,int yval)
	{
		x=x*2 + xval;
		y=y*2 + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}

	//从x执行dfs遍历,途径的所有点都标记
	//如果不能标记,那么返回false
	bool dfs(int x)
	{
		if(mark[x^1]) return false;//这两句的位置不能调换
		if(mark[x]) return true;
		mark[x]=true;
		S[c++]=x;
		for(int i=0;i<G[x].size();i++)
			if(!dfs(G[x][i])) return false;
		return true;
	}

	//判断当前2-SAT问题是否有解
	bool solve()
	{
		for(int i=0;i<2*n;i+=2)
		if(!mark[i] && !mark[i+1])
		{
			c=0;
			if(!dfs(i))
			{
				while(c>0) mark[S[--c]]=false;
				if(!dfs(i+1)) return false;
			}
		}
		return true;
	}
}ts;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		ts.init(n);
		while(m--){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			ts.add_clause(a, 1-c, b, 1-d);
		}
		if(ts.solve()) puts("YES");
		else puts("NO");
	}
}