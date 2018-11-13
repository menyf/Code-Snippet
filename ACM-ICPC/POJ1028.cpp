// Wrote by MenYifan on 2015-03-13 20:59:09
// Exe.Time 32ms Exe.Memory 716K
#include <stdio.h>
#include <iostream>
#include "string.h"
#include <stack>
using namespace std;
int main()
{
    stack<string>back,forwd;
    string str1,str2;
    str2="http://www.acm.org/";
    cin>>str1;
    while (str1!="QUIT") {
        if (str1=="VISIT") {
            back.push(str2);
            str2="";
            cin>>str2;
            cout<<str2<<endl;
            while (!forwd.empty()) {
                forwd.pop();
            }
        }
        
        if (str1=="BACK") {
            if (back.empty()) {
                cout<<"Ignored"<<endl;
            }
            else{
                forwd.push(str2);
                str2=back.top();
                back.pop();
                cout<<str2<<endl;
            }
        }
        
        if (str1=="FORWARD") {
            if (forwd.empty()) {
                cout<<"Ignored"<<endl;
            }
            else
            {
                back.push(str2);
                str2=forwd.top();
                forwd.pop();
                cout<<str2<<endl;
            }
        }
        cin>>str1;
    }
    return 0;
}
