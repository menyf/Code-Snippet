// Wrote by MenYifan on 2015-07-14 19:04:17
// Exe.Time 31ms Exe.Memory 16K

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
char s1[105],s2[105],s3[105];
int main(){
    scanf("%s",s1);
    scanf("%s",s2);
    int len=strlen(s1);
    for (int i=0; i<len; i++) {
        s3[i]=((s1[i]-'0')^(s2[i]-'0'))+'0';
    }
    s3[len]='\0';
    printf("%s",s3);
}