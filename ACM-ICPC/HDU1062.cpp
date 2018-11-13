// Wrote by MenYifan on 2015-03-13 17:18:06
// Exe.Time 0ms Exe.Memory 1588K
#include <stdio.h>
#include <iostream>
#include "cstring"
using namespace std;
/*void strrev(char str[])
{
    int i,j=0;
    char s[1009];
    for(i=strlen(str)-1;i>=0;i--)
        s[j++]=str[i];
    s[j]='\0';
    strcpy(str,s);
}*/
int main(){
    char s1[1050],s2[1050];
    char mid[1000];
    int n;
    scanf("%d",&n);
    getchar();
    for (int i=0; i<n; i++) {
        gets(s1);
        int t=0;
        for (int j=0; j<=strlen(s1); j++) {
            if (s1[j]==' '||j==strlen(s1)) {
                strrev(mid);
                strcat(s2, mid);
                strcat(s2, " ");
                memset(mid, '\0', sizeof(mid));
                t=0;
            }
            else{
                mid[t]=s1[j];
                t++;
            }
        }
        int l=strlen(s2);
        s2[l-1]='\0';
        printf("%s\n",s2);
        memset(s1, '\0', sizeof(s1));
        memset(s2, '\0', sizeof(s2));
    }
  
}