// Wrote by MenYifan on 2016-03-10 09:10:08
// Exe.Time 62ms Exe.Memory 1628K
//
//  HDU4884.cpp
//  Cfiles
//
//  Created by ??? on 16/3/9.
//  Copyright   2016? ???. All rights reserved.
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
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 100000+5
#define mod 1000000007
int in[1005],out[1005],num[1005],id[1005];
int main(){
    int T;
    bool blank=false;
    scanf("%d",&T);
    while (T--) {
        if (blank)
            printf("\n");

        int n,t,k,m,hh,mm,yy=0;
        cin>>n>>t>>k>>m;
        
        out[0]=0;
        for (int i=1; i<=m; i++) {
            out[i]=-1;
            scanf("%d:%d %d %d",&hh,&mm,&id[i],&num[i]);
            in[i]=hh*60+mm;
            if (in[i-1]%1440>in[i]){
                yy++;
            }
            in[i]+=1440*yy;
        }
        
        int mxt=0;
        for (int i=1; i<=m; i++) {
            mxt=max(out[i-1],mxt);
            if (out[i]!=-1){
                continue;
            }
            
            if (num[i]%k==0) {
                //?????????
                out[i]=max(mxt, in[i])+t*num[i]/k;
                continue;
            }
            else{
                //????????
                out[i]=max(mxt, in[i])+t*(num[i]/k+1);
            }
            
            int tmpk=k-num[i]%k;    //????????
            int start=out[i]-t; //??????i?????????
            for (int j=i+1; j<=m; j++) {
                if (in[j]>start||tmpk==0) {
                    break;
                }
                if (id[j]==id[i]) {
                    if (tmpk>=num[j]) {
                        out[j]=out[i];
                        tmpk-=num[j];
                    }
                    else{
                        num[j]-=tmpk;
                        tmpk=0;
                    }
                }
            }
            
        }
        
        
        for (int i=1; i<=m; i++) {
            printf("%02d:%02d\n",(out[i]/60)%24,out[i]%60);
        }
        
        blank=true;
    }
}