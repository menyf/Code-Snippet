// Wrote by MenYifan on 2015-11-22 22:21:43
// Exe.Time 9ms Exe.Memory 0K
//
//  20151122b.cpp
//  Cfiles
//
//  Created by ??? on 15/11/22.
//  Copyright   2015? ???. All rights reserved.
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
#define PI acos(-1)
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    char dna[60][1005];
    int t,n,len,ans;
    char mx;
    map<char, int>mp;
    scanf("%d",&t);
    while (t--) {
        ans=0;
        scanf("%d %d",&n,&len);
        for (int i=1; i<=n; i++) {
            scanf("%s",dna[i]);
        }
        for (int i=0; i<len; i++) {
            mp.clear();
            mx='.';
            mp[mx]=-1;
            for (int j=1; j<=n; j++) {
                if (mp.count(dna[j][i])==0)
                    mp[dna[j][i]]=1;
                else
                    mp[dna[j][i]]++;
                
                if (mp[mx]<mp[dna[j][i]]||(mp[mx]==mp[dna[j][i]]&&mx>dna[j][i]))
                    mx=dna[j][i];
            }
            printf("%c",mx);
            ans+=n-mp[mx];
        }
        printf("\n%d\n",ans);
    }
}