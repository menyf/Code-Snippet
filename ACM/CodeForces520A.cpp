// Wrote by MenYifan on 2015-03-13 16:52:28
// Exe.Time 15ms Exe.Memory 4K
#include <stdio.h>
#include "ctype.h"
#include "iostream"
using namespace std;
int main(){
    int n,sum=0,chara[26]={0};
    char ch;
    scanf("%d",&n);
    ch=getchar();
   for (int i=0; i<n; i++) {
        ch=getchar();
       ch=toupper(ch);
       if (chara[ch-'A']==0) {
           chara[ch-'A']=1;
           sum++;
       }
    }
    if (sum==26) {
        printf("YES");
    }
    else
        printf("NO");
}