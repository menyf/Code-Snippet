// Wrote by MenYifan on 2016-08-25 21:18:56
// Exe.Time 31ms Exe.Memory 1780K
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<iostream>
using namespace std;
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
char s1[40010];
char s2[40010];
char s3[40010];
char s4[40010];
char temp[40010];

int work(int len,char pat[])  //?????

{

   //int len = strlen(pat);

   int i=0,j=1,k=0;

   while(i<len && j<len && k<len)

   {

       int t = pat[(i+k)%len] - pat[(j+k)%len];

       if(!t) k++;

       else

       {

           if(t>0) j = j+k+1;

           else i = i+k+1;

           if(i == j) j++;

           k = 0 ;

       }

   }

   return i<j?i:j;

}

int  f(int n)
{
    for (int i=0;i<n;i++)
    {
        if(s3[i]<s4[i])
        {
            return 0;
        }
        else if(s3[i]>s4[i])
        {
            return 1;
        }
    }
    return -1;
}


int nex[40005];
inline void f1(char s2[],int *nex ,int M)
{
    int i=0,j=-1,k;
    nex [0]=-1;
    for (k=1;k<=M;k++)
    {
        nex [k]=0;
    }
    while (i<M)
    {
        if (j==-1||s2[i]==s2[j])
        {
            i++;
            j++;
            nex[i]=j;
        }
        else
        {
            j=nex[j];
        }
    }
}
inline int f2 (char s1[],char s2[],int N,int M,int nex [])
{
    int i=0,j=0,k=0;
    while (i<N)
    {
         if (s1[i]==s2[j]||j==-1)
        {
            i++;j++;
        }
        else
        {
            j=nex[j];
        }
        if (j>=M)
        {
            k=max(k,i%M);
            j=nex[j];
        }
    }
    return k;
}


int main ()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s1);
        for (int i=0;i<n;i++)
        {

            s2[i]=s1[n-1-i];
        }
        s1[n]=0;
        s2[n]=0;//cout <<'a';
        int where1=work(n,s1);
        int where2=work(n,s2);//cout <<'b';
       for (int i=where1, be=0;be<n;i=(i+1)%n,be++)
       {
           s3[be]=s1[i];//cout <<s1[i];
       }
       for (int i=where2, be=0;be<n;i=(i+1)%n,be++)
       {
           s4[be]=s2[i];
       }

       int flag=f(n);
      if(flag==1)
      {
          printf("%d 0\n",where1+1);
      }
      else
      {
          f1(s4,nex,n);
          strcpy(temp,s2);
          strcat(s2,temp);
         // cout <<s2<<endl;
          where2=n-f2(s2,s4,2*n,n,nex);
          if(where1+1<=where2&&flag==-1)
          {
               printf("%d 0\n",where1+1);
          }
          else
          {
              printf("%d 1\n",where2);
          }

      }

    }
}