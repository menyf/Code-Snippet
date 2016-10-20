//
//  20150724g.cpp
//  Cfiles
//
//  Created by 门一凡 on 15/7/24.
//  Copyright (c) 2015年 门一凡. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    long long max=0,sum=0,tmp=0,n,t;
    scanf("%lld",&t);
    while (t--) {
        max=0,sum=0,tmp=0;
        scanf("%lld",&n);
        while (n--) {
            scanf("%lld",&tmp);
            if (tmp>max) {
                max=tmp;
            }
            sum+=tmp;
        }
        sum-=max;
        if (max<=sum+1) {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}
