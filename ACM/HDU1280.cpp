// Wrote by MenYifan on 2015-03-15 22:34:49
// Exe.Time 530ms Exe.Memory 21192K

#include <stdio.h>
#include "algorithm"
#include <stdlib.h>
#include "ctype.h"
#include <iostream>
#include "string.h"
using namespace std;
int num[3000],sum[5000000];
int cmp(int x,int y){
    return x>y;
}
int main(){
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF) {
        int t=0;
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        for (int i=0; i<n; i++) {
            cin>>num[i];
            for (int j=0; j<i; j++) {
                sum[t++]=num[i]+num[j];
            }
        }
        sort(sum, sum+t,cmp);
        for (int i=0; i<m; i++) {
            printf("%d",sum[i]);
            if (i!=m-1) {
                printf(" ");
            }
            else
                printf("\n");
        }
    }
}