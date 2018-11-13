// Wrote by MenYifan on 2015-07-14 18:03:43
// Exe.Time 30ms Exe.Memory 4K
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 10000
int main(){
    char ss[]="hello";
    char s[105];
    scanf("%s",s);
    int len=strlen(s),t=0;
    for (int i=0; i<len; i++) {
        if (s[i]==ss[t]) {
            t++;
        }
    }
    if (t==5) {
        printf("YES\n");
    }
    else
        printf("NO\n");
}