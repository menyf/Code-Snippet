//POJ2299
//离散化＋树状数组

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 500005
int c[maxn],n;
int a[maxn]={},t[maxn]={};
int lowbit(int x){
    return x&(-x);
}
void update(int pos,int val){
    while (pos<=n) {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
int sum(int pos){
    int ans=0;
    while (pos>0) {
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    int tmp;
    while (scanf("%d",&n),n) {
        long long ans=0;
        memset(c, 0, sizeof(c));
        for (int i=1; i<=n; i++) {
            scanf("%d",&tmp);
            a[i]=t[i]=tmp;
        }
        sort(t+1, t+1+n);
        int cnt=unique(t+1, t+n+1)-t-1;
        for (int i=1; i<=n; i++) {
            a[i]=lower_bound(t+1, t+1+cnt, a[i])-t;
        }
        
        for (int i=1; i<=n; i++) {
            update(a[i], 1);
            ans+=i-sum(a[i]);
        }
        cout<<ans<<endl;
    }
}
