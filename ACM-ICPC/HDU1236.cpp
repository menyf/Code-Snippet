// Wrote by MenYifan on 2015-03-16 12:52:38
// Exe.Time 202ms Exe.Memory 1808K

#include <stdio.h>
#include "algorithm"
#include <stdlib.h>
#include "ctype.h"
#include <iostream>
#include "string.h"
#include "math.h"
using namespace std;

struct student{
    char idchar[100],idchar1[100];//idchar1???????
    int grade,idint;
};

int cmp(student a,student b){
    if (a.grade!=b.grade) {
        return a.grade>b.grade;
    }
    else
        return a.idint<b.idint;
}
int main(){
    int n,m,g;
    student s[1050];
    int point[20];
    int count=0;
    scanf("%d",&n);
    while (n!=0) {
        scanf("%d %d",&m,&g);
        memset(point, 0, sizeof(point));
        memset(&s,0,sizeof(s));
        int t,passcount=0;
        for (int i=0; i<m; i++) {
            scanf("%d",point+i);
        }
        for (int i=0; i<n; i++) {
            scanf("%s",s[i].idchar);
           // printf("%s",s[i].idchar);
            sscanf(s[i].idchar, "%*[A-Za-z]%[0-9]",s[i].idchar1);
          //  printf("%s",s[i].idchar1);
            s[i].idint=atoi(s[i].idchar1);
            scanf("%d",&count);
            for (int j=0; j<count; j++) {
                scanf("%d",&t);
                s[i].grade+=point[t-1];
            }
            if (s[i].grade>=g) {
                passcount++;
            }
        }
        sort(s, s+n, cmp);
        printf("%d\n",passcount);
        for (int i=0; i<passcount; i++) {
            printf("%s %d\n",s[i].idchar,s[i].grade);
        }
        scanf("%d",&n);
    }
}