#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[50][15]= {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
char b[50][15]= {"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char c[50][15]= {"","thousand","million","billion"};
string gao(int n)
{
    string s = "";
    if(n==0) {s+="zero"; return s;}
    int t=n/100,t1=n/10%10,t2=n%10,t3=n%100;
    if (t) s+=a[t],s+=" hundred";//printf("%s hundred",a[t]);
    if (t3)
    {
        if (t) s+=" and ";//printf(" and ");
        if (t3<=20) s+=a[t3]; //printf("%s",a[t3]);
        else
        {
            s+=b[t3/10];//printf("%s",b[t3/10]);
            if (t2) s+="-",s+=a[t2];//printf("-%s",a[t2]);
        }
    }
    return s;
}
int cont(string s){
    int vis[30]={};
    int cnt = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]>='a'&&s[i]<='z') {
            cnt++;
        }
    }
    return cnt;
}
int ans[1005];
int main()
{
    for (int i=1; i<=999; i++) {
        ans [i] = cont(gao(i));
        ans [i] += ans[i-1];
    }
    ans[1000]=11+ans[999];
    
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        cout<<ans[n]<<endl;
    }
    return 0;
}
