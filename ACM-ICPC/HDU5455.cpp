// Wrote by MenYifan on 2016-08-27 13:37:24
// Exe.Time 15ms Exe.Memory 1620K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=1000000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char str[maxn];
int main(){
    int T,cas=1;
    scanf("%d",&T);
    getchar();
    while (T--) {
       // scanf("%s",str+1);
        gets(str+1);
        int fir = -1;
        int pre = 0;
        int len = strlen(str+1);
        if (len == 0) {
            printf("Case #%d: %d\n",cas++,-1);
            continue;
        }
        int cnt = 0;
        bool flag = true;
        for (int i=1; i<=len; i++) {
            if (str[i]=='c') {
                cnt++;
                if (fir == -1) {
                    fir = i;
                }
                else{
                    if (i - pre <= 2) {
                        flag = false;
                    }
                }
                pre = i;
            }
            else if (str[i]!='f'){
                flag = false;
            }
        }
        
        
        if (fir == -1) {
            cnt = len/2 + len %2;
        }
        else{
            if (fir - 1 + len - pre < 2) {
                flag = false;
            }
        }
        
        if (flag) {
            printf("Case #%d: %d\n",cas++,cnt);
        }
        else{
            printf("Case #%d: %d\n",cas++,-1);
        }
        
    }
    return 0;
}

/*
 sort(p+1, p+n+1,cmp2);
 ll ans= 0;
 if (a>0) {
 ans += p[n].sq*a;
 p[n].vis = 1;
 }
 else if(a<0){
 ans += p[1].sq * a;
 p[1].vis = 1;
 }
 sort(p+1, p+n+1, cmp);
 if (b>0) {
 if (p[n].vis==0) {
 ans += b * p[n].num;
 }
 else{
 ans += b*p[n-1].num;
 }
 }
 else{
 if (p[1].vis==0) {
 ans += b * p[1].num;
 }
 else{
 ans += b * p[2].num;
 }
 }
*/