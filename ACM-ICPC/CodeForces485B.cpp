// Wrote by MenYifan on 2015-05-24 21:43:07
// Exe.Time 30ms Exe.Memory 12K
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define maxn 1000
using namespace std;
int main(){
    long long n,i,tmpx[maxn],tmpy[maxn];
    cin>>n;
    for (i=0; i<n; i++) {
        cin>>tmpx[i]>>tmpy[i];
    }
    sort(tmpx, tmpx+n);
    sort(tmpy, tmpy+n);
    
    long long area=max(tmpx[n-1]-tmpx[0],tmpy[n-1]-tmpy[0]);
    cout<<area*area<<endl;
}