// Wrote by MenYifan on 2015-03-13 19:49:06
// Exe.Time 32ms Exe.Memory 716K
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace::std;
int main(){
    char s[250];
    scanf("%s",s);
    sort(s,s+strlen(s));
    string str;
    str=s;
    //sort(str.begin(), str.end());
    do{
    cout<<str<<endl;
    }while (next_permutation(str.begin(), str.end()));
}
