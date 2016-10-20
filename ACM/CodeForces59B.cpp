// Wrote by MenYifan on 2015-07-14 18:58:39
// Exe.Time 30ms Exe.Memory 4K
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int n,a,tmp=0,ans=0;
    bool flag=true,flag2=true;
    cin>>n;
    
    for (int i=0; i<n; i++) {
        cin>>a;
        if (a%2==0)
            ans+=a;
        else{
            if (flag2) {
                tmp=a;
                flag2=false;
            }
            if (flag) {
                flag=false;//???????
            }
            else
                flag=true;//???????
            if (a<tmp) {
                tmp=a;
            }
            ans+=a;
        }
    }
    if (flag) {
        ans-=tmp;
    }
    if (ans%2==0) {
        printf("0");
    }
    else
        printf("%d",ans);
}