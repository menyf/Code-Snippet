#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#include<string>  
#include<algorithm>  
#include<math.h>  
#include<iomanip>  
#include<queue>  
#include<map>  
using namespace std;

int main()
{
    int Max = -1;
    bool flag = false;
    map<string, string> ss;
    map<string, int> st;
    char Name[85], Party[85];
    int n;
    cin>>n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(Name);
        gets(Party);
        ss[Name] = Party;
    }
    cin>>n;
    getchar();
    string result;
    for (int i = 0; i< n; i++)
    {
        gets(Name);
        if (ss[Name] == "")
        {
            continue;
        }
        int nCount = ++st[Name];
        if (nCount > Max)
        {
            flag = true;
            result = Name;
            Max = nCount;
        }
        else
        {
            if (nCount == Max)
            {
                flag = false;
            }
        }
    }
    if (flag)
    {
        cout<<ss[result]<<endl;
    }
    else
    {
        cout<<"tie"<<endl;
    }
    return 0;
}
