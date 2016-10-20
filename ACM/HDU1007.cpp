// Wrote by MenYifan on 2015-05-22 20:56:06
// Exe.Time 951ms Exe.Memory 3588K
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 100005;

// ?????????
struct point//??????
{
    double x,y;
}p[maxn];

int a[maxn];//????????????2min(dl,dh)????????

int cmpx(point a,point b)//?n????????????
{
    return a.x<b.x;
}

int cmpy(int a,int b)//??????????????????????????
{
    return p[a].y<p[b].y;
}

inline double dis(point a,point b)//???????
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closest(int low,int high)//?????
{
    int i,j,k;
    if(low+1==high)//?????
        return dis(p[low],p[high]);
    if(low+2==high)//?????
        return min(dis(p[low],p[high]),min(dis(p[low],p[low+1]),dis(p[low+1],p[high])));
    int mid=(low+high)>>1;//????????????
    double d=min(closest(low,mid),closest(mid+1,high));
    for(i=low,k=0;i<=high;i++)//?x???p[mid].x-d  ~  p[mid].x+d?????????
    {
        if(p[i].x >=p[mid].x-d&&p[i].x<=p[mid].x+d)
            a[k++]=i;//??????????
    }
    sort(a,a+k,cmpy);//?y????????
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(p[a[j]].y-p[a[i]].y>=d)//??????
                break;
            d=min(d,dis(p[a[i]],p[a[j]]));
        }
    }
    return d;
}
int main()
{
    int i,n;
    while(scanf("%d",&n) != EOF)//n??
    {
        if (n==0) {
            break;
        }
        for(i = 0 ; i < n ; ++i)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        sort(p , p + n , cmpx);//?x????????
        printf("%.2lf\n",closest(0 , n - 1)/2);//????????
    }
    return 0;
}



