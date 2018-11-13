// Wrote by MenYifan on 2015-03-15 19:15:19
// Exe.Time 0ms Exe.Memory 2792K
#include <stdio.h>
#include "stdbool.h"
#include <string.h>
#include "stdlib.h"
#include <algorithm>
#include "iostream"
using namespace std;
int main(){
    char num[1100];
    while (scanf("%s",num)!=EOF) {
        getchar();
        char num1[1100][1100];
        int num2[10005];
        memset(num1, '\0',sizeof(num1));
        memset(num2, 0, sizeof(num2));
        int r=0,c=0,key=0;
        for (int i=0; i<strlen(num); i++) {
            if (num[i]!='5') {
                num1[r][c++]=num[i];
                key=1;
            }
            else if(num[i]=='5'&&key==1){
                r++;
                c=0;
                key=0;
            }
        }
        if (key==1) {
            r++;
        }
        for (int i=0; i<r; i++) {
            num2[i]=atoi(num1[i]);
        }
        sort(num2,num2+r);
        for (int i=0; i<r; i++) {
            if (i==0) {
                printf("%d",num2[i]);
            }
            else
                printf(" %d",num2[i]);
        }
        printf("\n");
        memset(num, '\0', sizeof(num));
    }
}