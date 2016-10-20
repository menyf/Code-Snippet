// Wrote by MenYifan on 2015-03-20 22:18:56
// Exe.Time 0ms Exe.Memory 1580K
//
//  20150320h.cpp
//  Cfiles
//
//  Created by ??? on 15/3/20.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
using namespace std;
long long int Gcd(long long int a,long long int b)
{
    if(b == 0)
        return a;
    return Gcd(b, a % b);
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        long long int num,result=0;
        scanf("%I64d",&result);
        for (int i=1; i<n; i++) {
            scanf("%I64d",&num);
            result=result*num/Gcd(result, num);
        }
        printf("%I64d\n",result);
    }
}