// Wrote by MenYifan on 2015-07-21 11:36:45
// Exe.Time 15ms Exe.Memory 1580K
//
//  20150720e.cpp
//  Cfiles
//
//  Created by ??? on 15/7/20.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 450
#define MAX 450
void sum(char a[],char b[],char d[]){
    char c[MAX];
    int i,k=0,al=0,bl=0,cl=0;
    while(a[al])
        al++;
    al--;//al????a???
    while(b[bl])
        bl++;
    bl--;//bl????b???
    
    cl=al>bl?al:bl;//cl?max(al,bl)?1
    cl++;
    
    c[cl+1]='\0';
    while(cl>=0)
    {
        i=(al>=0?a[al]-'0':0) + (bl>=0?b[bl]-'0':0) + k;
        k=i/10;c[cl]='0'+i%10;
        al--;bl--;cl--;
    }
    
    int len=strlen(c);
    if (c[0]=='0') {
        for (int i=1; i<len; i++) {
            c[i-1]=c[i];
            if (i==len-1) {
                c[i]='\0';
            }
        }
    }
    strcpy(d, c);
}
int main(){
    char a[maxn],b[maxn],a1[maxn],b1[maxn],a2[maxn],b2[maxn],ans1[maxn],ans2[maxn],tmp[]="1";
    int maxlen;
    while (scanf("%s%s",a,b)!=EOF) {
        int i=0,la1=0,la2=0,lb1=0,lb2=0,len=0,pos=0;
//        len=0;
        while (a[i]!='.') {
            if (a[i]=='\0') {
                la2=0;
                goto l1;
            }
            a1[la1]=a[i];
            la1++;i++;
        }//a la1 a1
        a1[la1]='\0';
        
        i++;
        while (a[i]!='\0') {
            a2[la2]=a[i];
            la2++;i++;
        }//a la2 a2
    l1:     a2[la2]='\0';
        
        i=0;
        while (b[i]!='.') {
            if (b[i]=='\0') {
                lb2=0;
                goto l2;
            }
            b1[lb1]=b[i];
            lb1++;i++;
        }//b lb1 b1
        b1[lb1]='\0';
        
        i++;
        while (b[i]!='\0') {
            b2[lb2]=b[i];
            lb2++;i++;
        }//b lb2 b2
    l2:      b2[lb2]='\0';
//        pf("a1 : %s \na2 : %s\nb1 : %s\nb2 : %s\nans2 : %s\n--------\n",a1,a2,b1,b2,ans2);
        
        
        sum(a1, b1, ans1);
        
//        pf("ans1:%s\n",ans1);
        
        if (la2==0) {
            a2[0]='0';
            a2[1]='\0';
            la2=1;
        }
        if (lb2==0) {
            b2[0]='0';
            b2[1]='\0';
            lb2=1;
        }
        
        if (lb2>la2) {
            for (int i=la2; i<lb2; i++) {
                a2[i]='0';
            }
            maxlen=lb2;
            a2[lb2]='\0';
        }
        else{
            for (int i=lb2; i<la2; i++) {
                b2[i]='0';
            }
            maxlen=la2;
            b2[la2]='\0';
        }
        
        sum(a2, b2, ans2);
        
//        pf("a1 : %s \na2 : %s\nb1 : %s\nb2 : %s\nans2 : %s\n--------\n",a1,a2,b1,b2,ans2);
        
        len=strlen(ans2);
        if (len>maxlen) {
            sum(ans1, tmp, ans1);
            for (int i=0; i<len-1; i++) {
                ans2[i]=ans2[i+1];
            }
            ans2[len-1]='\0';
        }
        
        for (int i=0; i<len; i++) {
            if (ans2[i]!=0) {
                pos=i;
            }
        }
        ans2[pos+1]='\0';
        len=strlen(ans2);
        for (i=len-1; i>=0; i--) {
            if (ans2[i]!='0') {
                break;
            }
            if (ans2[i]=='0') {
                ans2[i]='\0';
            }
        }
        if (i==-1) {
            pf("%s\n",ans1);
        }
        else
            pf("%s.%s\n",ans1,ans2);
        MemC(a1);
        MemC(a2);
        MemC(b1);
        MemC(b2);
        MemC(ans1);
        MemC(ans2);
        
    }
}