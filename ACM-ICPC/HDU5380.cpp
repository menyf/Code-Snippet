// Wrote by MenYifan on 2016-05-02 21:52:31
// Exe.Time 296ms Exe.Memory 6300K
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
#define ll long long
#define maxn 200005
#define DB cout<<sum<<" "<<ans<<" "<<endl
using namespace std;

struct node {
	ll val,cnt;
	node(){};
	node(ll v,ll c):val(v),cnt(c){};
};
int n,c;
ll ans,sum;
ll dis[maxn],buy[maxn],sell[maxn];

void work() {
	ans = 0;
	deque<node> q;
	q.push_front(node(buy[0],c));//??????
	ans+=buy[0]*c;//?????
	sum = c;//???

	for(int i=1;i<=n;i++) {
		ll d = dis[i]-dis[i-1];//???
		sum = c-d;
		//?????
		while(d) {
			node tmp = q.front();
			q.pop_front();
			if(tmp.cnt>d) {
				q.push_front(node(tmp.val,tmp.cnt-d));
				d = 0;
			} else {
				d-=tmp.cnt;
			}
		}
		//????????????
		ll cnt = 0;//????????????
		while(!q.empty()) {
			if(q.front().val>=sell[i])break;
			else {
				cnt+=q.front().cnt;
				q.pop_front();
			}
		}
		if(cnt)q.push_front(node(sell[i],cnt));
		//????????????
		while(!q.empty()) {
			node tmp = q.back();
			if(tmp.val>buy[i]) {
				q.pop_back();//??????????????????
				sum-=tmp.cnt;
				ans-=tmp.val*tmp.cnt;
			}else break;
		}
		q.push_back(node(buy[i],c-sum));
		ans+=q.back().val*q.back().cnt;
	}
	//???????????
	while(!q.empty()) {
		node tmp = q.front();
		q.pop_front();
		ans-=tmp.val*tmp.cnt;
	}

	printf("%I64d\n",ans);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&c);
		for(int i=1;i<=n;i++) {
			scanf("%I64d",dis+i);
		}

		for(int i=0;i<=n;i++) {
			scanf("%I64d%I64d",buy+i,sell+i);
		}
		work();
	}
	return 0;
}