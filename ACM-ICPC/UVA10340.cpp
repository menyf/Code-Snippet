// Wrote by MenYifan on 2015-11-01 18:43:48
// Exe.Time 0ms Exe.Memory 0K
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
#define maxn 100050
int main(){
    char str1[maxn],str2[maxn];
    while(scanf("%s%s",str1,str2)!=EOF){
        int len1=strlen(str1);
        int len2=strlen(str2);
        int index=0;
        for(int i=0;i<len2&&index<len1;i++){
            if(str1[index]==str2[i]) index++;
        }
        if(index==len1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
