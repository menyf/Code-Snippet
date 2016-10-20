// Wrote by MenYifan on 2015-07-27 16:55:05
// Exe.Time 2454ms Exe.Memory 14812K
#include <map>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    map<string, string>mp;
    char s[30],s1[15],s2[15];
    string str1,str2;
    while (1) {
        gets(s);
        if (s[0]=='\0') break;
        sscanf(s,"%s%s", s1,s2);
        str1=s1;str2=s2;
        mp[str2]=str1;
    }
    while (cin>>s1)
        if (mp.find(s1)!=mp.end()) cout<<mp[s1]<<endl;
        else cout<<"eh"<<endl;
}