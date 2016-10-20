// Wrote by MenYifan on 2015-09-27 22:27:38
// Exe.Time 49ms Exe.Memory 0K
//
//  20150927c.cpp
//  Cfiles
//
//  Created by ??? on 15/9/27.
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
char s[250];
bool match(char a,char b){
    if (a=='('&&b==')') {
        return 1;
    }
    else if (a=='['&&b==']') {
        return 1;
    }
    else return 0;
}
bool le(char c){
    if (c=='('||c=='[') {
        return 1;
    }
//    bug;
    return 0;
}
int main(){
    int t;
    cin>>t;
    getchar();
    while (t--) {
        bool flag=true;
        stack<char> st;
        if (!st.empty()) st.pop();
        gets(s);
//        cout<<s<<endl;
        if (s[0]=='\n') cout<<"Yes"<<endl;
        for (int i=0; s[i]; i++) {
            if (le(s[i])) {
                st.push(s[i]);
            }
            else if (!st.empty()&&match(st.top(), s[i]))
                st.pop();
            else{
                flag=false;
            }
        }
        if (flag&&st.empty()) {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
}