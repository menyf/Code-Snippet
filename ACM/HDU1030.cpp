// Wrote by MenYifan on 2015-12-14 13:15:56
// Exe.Time 0ms Exe.Memory 1404K
#include <cmath>
#include <cstdio>
int main(){
    int a,b,x1,y1,z1,x2,y2,z2;
    while (scanf("%d %d",&a,&b)!=EOF) {
        x1=ceil(sqrt(a));
        x2=ceil(sqrt(b));
        y1=ceil((a-(x1-1)*(x1-1))/2.0);
        y2=ceil((b-(x2-1)*(x2-1))/2.0);
        z1=ceil((x1*x1-a+1)/2.0);
        z2=ceil((x2*x2-b+1)/2.0);
        printf("%d\n",abs(x1-x2)+abs(y1-y2)+abs(z1-z2));
    }
}