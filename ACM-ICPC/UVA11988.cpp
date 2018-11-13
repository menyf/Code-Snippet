// Wrote by MenYifan on 2015-10-11 20:16:32
// Exe.Time 96ms Exe.Memory 0K
//
//  20151011b.cpp
//  Cfiles
//
//  Created by ??? on 15/10/11.
//  Copyright   2015? ???. All rights reserved.
//

#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <list>
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
#define maxn 100005
char s[maxn];
char tmp[maxn];
list<string> ans;
string tmpp;
int main(){
    int index;
    while (scanf("%s",s)!=EOF) {
        bool flag=true; //true?? false??
        int len=strlen(s);
        index=0;
        for (int i=0; i<len; i++) {
            if (s[i]=='[') {
                if (flag) {
                    tmp[index]='\0';
                    tmpp=tmp;
                    ans.push_front(tmpp);
                }
                else{
                    tmp[index]='\0';
                    tmpp=tmp;
                    ans.push_back(tmpp);
                }
                index=0;
                flag=true;
                
            }
            else if (s[i]==']'){
                if (flag) {
                    tmp[index]='\0';
                    tmpp=tmp;
                    ans.push_front(tmpp);
                }
                else{
                    tmp[index]='\0';
                    tmpp=tmp;
                    ans.push_back(tmpp);
                }
                index=0;
                flag=false;
            }
            else{
                tmp[index++]=s[i];
            }
        }
        if (flag) {
            tmp[index]='\0';
            tmpp=tmp;
            ans.push_front(tmpp);
        }
        else{
            tmp[index]='\0';
            tmpp=tmp;
            ans.push_back(tmpp);
        }
        
        list<string>::iterator i=ans.begin();
        for (; i!=ans.end(); i++) {
            cout<<*i;
        }
        cout<<endl;
        ans.clear();
    }
    
}