// Wrote by MenYifan on 2015-03-08 22:04:29
// Exe.Time 0ms Exe.Memory 1576K

#include <stdio.h>
#include<cstring>
#include "queue"
#include "iostream"
using namespace std;
int main(){
    int a[3];
    scanf("%d%d%d",a,a+1,a+2);
    for (int i=0; i<3; i++) {
        if (a[i]<=168) {
            printf("CRASH %d\n",a[i]);
            return 0;
        }
    }
    printf("NO CRASH\n");
}
