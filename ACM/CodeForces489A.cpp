// Wrote by MenYifan on 2015-05-24 20:49:40
// Exe.Time 15ms Exe.Memory 8K
//
//  20150524a.cpp
//  Cfiles
//
//  Created by ??? on 15/5/24.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int *p1,int *p2){
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int main(){
    int n,mrk;
    int a[3000];
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",a+i);
    }
    cout<<n<<endl;
    for (int i=0; i<n; i++) {
        int min=a[i];
        mrk=i;
        for (int j=i+1; j<n; j++) {
            if (min>a[j]) {
                min=a[j];
                mrk=j;
            }
        }
        swap(a+i, a+mrk);
        printf("%d %d\n",i,mrk);
    }
}