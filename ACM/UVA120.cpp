// Wrote by MenYifan on 2015-09-20 21:05:28
// Exe.Time 3ms Exe.Memory 0K
//
//  20150920a.cpp
//  Cfiles
//
//  Created by ??? on 15/9/20.
//  Copyright   2015? ???. All rights reserved.
//

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
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define vset(a,val) memset(a,val,sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    int a[100]={},b[100]={},cnt;
    int index=0,j;
    char ch;
    while (scanf("%d",&a[index++])!=EOF) {
        while(scanf("%c",&ch)&&ch!='\n'){
            scanf("%d",&a[index++]);
        }
        cnt=index;
        for (int i=0; i<index; i++) {
            b[i]=a[i];
            cout<<a[i];
            i==index-1?cout<<endl:cout<<" ";
        }
        
        for (int i=cnt-1; i>0; i--) {
            for (j=0; j<cnt-1; j++) {
                if (b[j]>b[j+1]) {
                    break;
                }
            }
            if (j==cnt-1)
                break;
            
            int mx=b[i],pos=i;
            for (j=i; j>=0; j--) {
                if (b[j]>mx) {
                    mx=b[j];
                    pos=j;
                }
            }
            if (pos!=0){
                reverse(b, b+pos+1);
                reverse(b, b+i+1);
                cout<<cnt-pos<<" "<<cnt-i<<" ";
            }
            else if (pos==0){
                reverse(b, b+i+1);
                cout<<cnt-i<<" ";
            }
        }
        cout<<0<<endl;
        index=0;
    }
}
