// Wrote by MenYifan on 2015-05-17 18:38:05
// Exe.Time 15ms Exe.Memory 36K
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 10050
#define inf 9999999
int main(){
    int i=1,tmp=0,n;
    int a[MAX]={};
    scanf("%d",&n);
    for (; i<10000; i++) {
        tmp+=i;
        a[i]=a[i-1]+tmp;
        if (n<a[i]) {
            break;
        }
    }
    printf("%d",i-1);
    return 0;
}