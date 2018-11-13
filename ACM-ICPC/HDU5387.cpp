// Wrote by MenYifan on 2016-04-27 19:10:24
// Exe.Time 31ms Exe.Memory 1580K
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		int ss = s;
		int mm = s + m*60;
		int hh = s + m*60 + h*3600;

		mm*=12;
		ss*=720;
		while(ss>=43200)ss-=43200;
		while(mm>=43200)mm-=43200;
		while(hh>=43200)hh-=43200;

		int hm = abs(hh-mm);
		int hs = abs(hh-ss);
		int ms = abs(mm-ss);
		int gcd = 120;
		if(hm!=0)gcd = __gcd(hm,120);
		int zhm = hm/gcd;
		int mhm = 120/gcd;
		if(zhm>mhm*180)zhm = mhm*360-zhm;
		gcd = 120;
		if(hs!=0)gcd = __gcd(hs,120);
		int zhs = hs/gcd;
		int mhs = 120/gcd;
		if(zhs>mhs*180)zhs = mhs*360-zhs;
		gcd = 120;
		if(ms!=0)gcd = __gcd(ms,120);
		int zms = ms/gcd;
		int mms = 120/gcd;
		if(zms>mms*180)zms = mms*360-zms;
		mhm==1?printf("%d ",zhm):printf("%d/%d ",zhm,mhm);
		mhs==1?printf("%d ",zhs):printf("%d/%d ",zhs,mhs);
		mms==1?printf("%d ",zms):printf("%d/%d ",zms,mms);
		puts("");
	}
	return 0;
}