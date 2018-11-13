// Wrote by MenYifan on 2015-03-15 19:39:07
// Exe.Time 187ms Exe.Memory 2736K
#include <stdio.h>
#include "algorithm"
#include <stdlib.h>
#include "ctype.h"
#include <iostream>
#include "string.h"
#include "map"
using namespace std;
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        int num[n];
        for (int i=0; i<n; i++) {
            scanf("%d",num+i);
        }
        sort(num, num+n);
        printf("%d\n",num[(n+1)/2]);
    }
}
