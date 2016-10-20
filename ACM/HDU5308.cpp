// Wrote by MenYifan on 2016-03-28 19:44:24
// Exe.Time 249ms Exe.Memory 1588K
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
void work1(int n){
    if (n<4) {
        printf("-1\n");
    }
    else if(n==4){
        puts("1 * 2");
        puts("5 + 3");
        puts("6 + 4");
    }
    else if (n==5){
        puts("1 * 2");
        puts("6 * 3");
        puts("7 - 4");
        puts("8 / 5");
    }
    else if (n==6){
        puts("1 + 2");
        puts("3 + 7");
        puts("4 + 8");
        puts("5 + 9");
        puts("10 - 6");
    }
    else if (n==7){
        puts("1 + 2");
        puts("8 + 3");//9 21
        puts("4 + 5");//10 14
        puts("10 + 6");//11 21
        puts("11 / 7");//12 3
        puts("9 + 12");
    }
    else if (n==8){
        puts("1 + 2");
        puts("9 / 3");
        puts("4 / 5");
        puts("10 - 11");
        puts("6 + 7");
        puts("13 + 8");
        puts("14 * 12");
    }
    else if (n==9){
        puts("1 + 2");
        puts("10 + 3");
        puts("4 + 5");
        puts("12 + 6");
        puts("13 / 7");
        puts("11 - 14");
        puts("15 + 8");
        puts("16 - 9");
    }
    else if (n==10){
        puts("1 * 2");
        puts("11 + 3");
        puts("12 + 4");
        puts("5 + 6");
        puts("14 + 7");
        puts("15 + 8");
        puts("16 + 9");
        puts("17 / 10");
        puts("13 / 18");
    }
    else if (n==11){
        puts("1 + 2");//12 22
        puts("3 + 4");//13 22
        puts("13 / 5");//14 2
        puts("12 + 14");
        puts("15 + 6");
        puts("16 + 7");
        puts("17 + 8");
        puts("18 - 9");
        puts("19 - 10");
        puts("20 - 11");
    }
    else if (n%2){
        //3+1 8+1
        int id=1;//???????????
        for (int i=2; i<=3; i++) {
            printf("%d + %d\n",i,id);
            id=(i==2)?(n+1):(id+1);
//            debug(id);
        }
        printf("%d / %d\n",id,4);
        id=5;
        for (int i=6; i<=12; i++) {
            printf("%d + %d\n",i,id);
//            debug(id);
            id=(i==6)?(n+4):(id+1);
        }
        printf("%d / %d\n",id++,13);
        printf("%d * %d\n",n+3,id++);
        
        for (int i=14; i<=n; i++) {
            if (i%2) {
                printf("%d + %d\n",id++,i);
            }
            else
                printf("%d - %d\n",id++,i);
        }
    }
    else{
        //4+1 6+1
        int id=1;//???????????
        for (int i=2; i<=4; i++) {
            printf("%d + %d\n",i,id);
            id=(i==2)?(n+1):(id+1);
        }
        printf("%d / %d\n",id,5);
        id=6;
        for (int i=7; i<=11; i++) {
            printf("%d + %d\n",i,id);
            id=(i==7)?(n+5):(id+1);
//                        debug(id);
        }
        printf("%d / %d\n",id++,12);
        printf("%d * %d\n",n+4,id++);
        
        for (int i=13; i<=n; i++) {
            if (i%2) {
                printf("%d + %d\n",id++,i);
            }
            else
                printf("%d - %d\n",id++,i);
        }

    }
    
}
int main(){
    int n;
//    for (int i=5; i<=20; i++) {
//        printf("%d\n",i);
//        work1(i);
//    }
    while (~scanf("%d",&n)) {
        work1(n);
    }
    return 0;
}