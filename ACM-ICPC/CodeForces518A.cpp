// Wrote by MenYifan on 2015-04-13 17:49:55
// Exe.Time 31ms Exe.Memory 16K
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 100050
int main(){
    char str1[105],str2[105],str3[105];
    scanf("%s",str1);
    scanf("%s",str2);
    int len=strlen(str1);
    str1[len-1]+=1;
    for (int i=len-1; i>=0; i--) {
        if (str1[i]>'z') {
            str1[i]-=26;
            str1[i-1]++;
        }
    }
    if (strcmp(str2, str1)>0) {
        printf("%s",str1);
    }
    else
        printf("No such string");
}