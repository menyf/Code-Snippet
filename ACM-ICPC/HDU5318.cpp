// Wrote by MenYifan on 2016-03-29 22:43:31
// Exe.Time 46ms Exe.Memory 2184K
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 100
#define Mod 1000000007
class Martix {
public:
        void clear();
        void Copy(Martix p);
        void Show();
        Martix operator* (const Martix &b)const;
        int n,m;
        long long mar[MAXN][MAXN];
};

void Martix::clear() {
        n = 0;
        m = 0;
        memset(mar,0,sizeof(mar));
}

Martix Martix::operator* (const Martix &b) const {
        Martix tmp;
        tmp.n = n;
        tmp.m = b.m;

        for(int i=0;i<n;i++) {
                for(int j = 0;j<b.m;j++) {
                        tmp.mar[i][j] = 0;
                }
        }

        for(int i=0;i<n;i++) {
                for(int j = 0;j<m;j++) {
                        if(!mar[i][j])continue;

                        for(int k = 0;k<b.m;k++) {
                                tmp.mar[i][k]+=mar[i][j]*b.mar[j][k],tmp.mar[i][k]%=Mod;
                        }
                }
        }
        return tmp;
}

void Martix::Copy(Martix p) {
        n = p.n;
        m = p.m;
        for(int i=0;i<n;i++) {
                for(int j = 0;j<m;j++) {
                        mar[i][j] = p.mar[i][j];
                }
        }
}

void Martix::Show() {
        cout<<"n: "<<n<<" "<<"m: "<<m<<endl;
        for(int i=0;i<n;i++) {
                for(int j= 0;j<m;j++) {
                        cout<<mar[i][j]<<" ";
                }
                cout<<endl;
        }
}

Martix Martix_pow(Martix A,long long k) {
        Martix ans;
        ans.clear();
        ans.n  = ans.m = A.n;

        for(int i=0;i<ans.n;i++) {
                ans.mar[i][i] = 1;
        }

        while(k) {
                if(k&1) {
                        ans.Copy(A * ans);
                }
                k>>=1;
                A.Copy(A*A);
        }

        return ans;
}

int arr[55];
long long a,b,cnt;

bool check1(int c) {
        for(int i=0;i<cnt;i++) {
                if(c==arr[i])return false;
        }
        return true;
}

bool check2(int x,int y) {
        int xx[11] = {0},yy[11] = {0};
        int r = 10;
        int f = 0,s = 0;

        for(int i = 1;i<=10;i++) {
                xx[i] = x%r;
                x/=r;
                if(!x){f = i;break;}
        }

        for(int i = 1;i<=10;i++) {
                yy[i] = y%r;
                y/=r;
                if(!y){s = i;break;}
        }

        int mm =min(f,s);
        for(int i=2;i<=mm;i++) {
                int cmp1 = 0,cmp2 = 0;
                for(int j = i,k = s;j>=1;j--,k--) {
                        cmp1 = cmp1*10+xx[j];
                        cmp2 = cmp2*10+yy[k];
                }

                if(cmp1==cmp2)return true;
        }

        return false;
}

int main() {
        int t;
        scanf("%d",&t);
        while(t--) {
                scanf("%I64d%I64d",&a,&b);
                cnt = 0;
                for(int i=0;i<a;i++) {
                        int c;
                        scanf("%d",&c);
                        if(check1(c)) {
                                arr[cnt++] = c;
                        }
                }

                Martix h;
                h.clear();
                h.n = cnt;
                h.m = cnt;

                for(int i=0;i<cnt;i++) {
                        for(int j=0;j<cnt;j++) {
//                                if(i==j)continue;
                                if(check2(arr[i],arr[j])) {
                                        h.mar[i][j] = 1;
                                }
                        }
                }

                h.Copy(Martix_pow(h,b-1));
                long long answer = 0;
                for(int i=0;i<cnt;i++) {
                        for(int j = 0;j<cnt;j++) {
                                answer+=h.mar[i][j],answer%=Mod;
                        }
                }

                printf("%I64d\n",answer);
        }
        return 0;
}
