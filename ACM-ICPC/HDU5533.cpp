// G - Dancing Stars on Me
// Created by 门一凡 on 16/10/9.
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define fre() freopen("data_in.txt","r",stdin); \
			  freopen("data_out.txt","w",stdout);
#define debug(x) cout<<"Debug : --- "<<x<<" ---"<<endl;
#define debug2(x,y) cout<<"Debug : --- "<<x<<" , "<<y<<" ---"<<endl;
#define debug3(x,y,z) cout<<"Debug : --- "<<x<<" , "<<y<<" , "<<z<<" ---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
struct POINT
{
	double x;
	double y;
	POINT(double a=0, double b=0) { x=a; y=b;} //constructor
	void in(){
		scanf("%lf%lf",&x,&y);
	}
}p[105],ans[105];
double multiply(POINT sp,POINT ep,POINT op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}
double dist(POINT p1,POINT p2)                // 返回两点之间欧氏距离
{
	return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
/**********************************************
 寻找凸包的graham 扫描法
 PointSet为输入的点集；
 ch为输出的凸包上的点集，按照逆时针方向排列;
 n为PointSet中的点的数目
 len为输出的凸包上的点的个数
 **********************************************/
void Graham_scan(POINT PointSet[],POINT ch[],int n,int &len)
{
	int i,j,k=0,top=2;
	POINT tmp;
	// 选取PointSet中y坐标最小的点PointSet[k]，如果这样的点有多个，则取最左边的一个
	for(i=1;i<n;i++)
		if ( PointSet[i].y<PointSet[k].y || (PointSet[i].y==PointSet[k].y) && (PointSet[i].x<PointSet[k].x) )
			k=i;
	tmp=PointSet[0];
	PointSet[0]=PointSet[k];
	PointSet[k]=tmp; // 现在PointSet中y坐标最小的点在PointSet[0]
	for (i=1;i<n-1;i++) /* 对顶点按照相对PointSet[0]的极角从小到大进行排序，极角相同的按照距离PointSet[0]从近到远进行排序 */
	{
		k=i;
		for (j=i+1;j<n;j++)
			if ( multiply(PointSet[j],PointSet[k],PointSet[0])>0 ||  // 极角更小
				(multiply(PointSet[j],PointSet[k],PointSet[0])==0) && /* 极角相等，距离更短 */
				dist(PointSet[0],PointSet[j])<dist(PointSet[0],PointSet[k])
				)
				k=j;
		tmp=PointSet[i];
		PointSet[i]=PointSet[k];
		PointSet[k]=tmp;
	}
	ch[0]=PointSet[0];
	ch[1]=PointSet[1];
	ch[2]=PointSet[2];
	for (i=3;i<n;i++)
	{
		while (multiply(PointSet[i],ch[top],ch[top-1])>=0)
			top--;
		ch[++top]=PointSet[i];
	}
	len=top+1;
}
/* 返回顶角在o点，起始边为os，终止边为oe的夹角(单位：弧度)
 角度小于pi，返回正值
 角度大于pi，返回负值
 可以用于求线段之间的夹角
 原理：
 r = dotmultiply(s,e,o) / (dist(o,s)*dist(o,e))
 r'= multiply(s,e,o)

 r >= 1 angle = 0;
 r <= -1 angle = -PI
 -1<r<1 && r'>0 angle = arccos(r)
 -1<r<1 && r'<=0 angle = -arccos(r)
 */

double angle(POINT o,POINT s,POINT e)
{
	double cosfi,fi,norm;
	double dsx = s.x - o.x;
	double dsy = s.y - o.y;
	double dex = e.x - o.x;
	double dey = e.y - o.y;

	cosfi=dsx*dex+dsy*dey;
	norm=(dsx*dsx+dsy*dsy)*(dex*dex+dey*dey);
	cosfi /= sqrt( norm );

	if (cosfi >=  1.0 ) return 0;
	if (cosfi <= -1.0 ) return -3.1415926;

	fi=acos(cosfi);
	if (dsx*dey-dsy*dex>0) return fi;      // 说明矢量os 在矢量 oe的顺时针方向
	return -fi;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n ; i++){
			p[i].in();
		}
		int len;
		Graham_scan(p, ans, n, len);
		if (len != n) {
			puts("NO");
		}
		else {
			int cnt = 1;
			double dis = dist(ans[0], ans[n-1]);
			for (int i = 0 ; i < n-1 ; i++) {
				double tmp = dist(ans[i], ans[i+1]);
				if (fabs(dis - tmp) < eps) {
					cnt++;
				}
				else {
					break;
				}
			}
			if (cnt != n) {
				puts("NO");
				continue;
			}
			double ang = angle(ans[0], ans[n-1], ans[1]);
			cnt = 1;
			for (int i = 1 ; i < n; i++) {
				double tmp = angle(ans[i], ans[i-1], ans[(i+1)%n]);
				if (fabs(tmp - ang) < eps) {
					cnt++;
				}
				else break;
			}
			if (cnt != n) {
				puts("NO");
			}
			else
				puts("YES");
		}
	}
}