// Wrote by MenYifan on 2015-03-13 20:02:57
// Exe.Time 141ms Exe.Memory 704K
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace::std;
bool cmp(int a,int b){
    double A,B;
    A=a>='a'?(a-31.5):a;
    B=b>='a'?(b-31.5):b;
    return A<B;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        char str[15];
        scanf("%s",str);
        int l=strlen(str);
        sort(str, str+l, cmp);
        string s=str;
        do {
            cout<<s<<endl;
        }while ((next_permutation(s.begin(), s.end(),cmp)));
    }
}