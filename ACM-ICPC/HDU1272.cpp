// Wrote by MenYifan on 2016-03-30 17:22:55
// Exe.Time 46ms Exe.Memory 2348K
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

bool flag = true;
int view[100005];
int mark[100005];
int mi = 100005,mx = -1;

void unit() {
        mi = 100005,mx = -1;
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=100000;i++) {
                view[i] = i;
        }
}

int find_set(int x) {
        int r = x;
        while(view[r]!=r) {
                r = view[r];
        }
        return r;
}

bool IsCyclization(int x,int y) {
        int f = find_set(x);
        int s = find_set(y);
        if(f==s)return true;
        else return false;
}

void add_set(int x,int y) {
        mx = max(max(x,mx),y);
        mi = min(min(x,mi),y);
        mark[x] = 1;
        mark[y] = 1;
        if(IsCyclization(x,y))flag = false;
        else {
                int f = find_set(x);
                int s = find_set(y);
                view[f] = s;
        }
        return;
}

void work() {
        if(mi==100005&&mx==-1)puts("Yes");
        else {
                if(flag==false)puts("No");
                else {
                        int cnt = 0;
                        for(int i=mi;i<=mx;i++) {
                                if(view[i]==i&&mark[i]) {
                                        cnt++;
                                }
                        }
                        cnt==1?puts("Yes"):puts("No");
                }
        }
        unit();
}

int main() {
        int x,y;
        unit();

        while(scanf("%d%d",&x,&y)&&(~x||~y)) {
                if(!x&&!y)work();
                else add_set(x,y);
        }
        return 0;
}
