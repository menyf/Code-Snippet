// Wrote by MenYifan on 2016-02-05 11:14:03
// Exe.Time 47ms Exe.Memory 756K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
	int t,tmp,cnt;
	cin>>t;
	vector<int> v;
	while(t--){
		cin>>cnt;
		v.clear();
		for (int i = 0; i < 10; ++i)
		{
			cin>>tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		cout<<cnt<<" "<<v[7]<<endl;
	}
}
