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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=50000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
#define lson l,m,rt<<1          //预定子左树
#define rson m+1,r,rt<<1|1      //预定右子树
struct node {
    ll a[3][3];
    node(){
        memset(a, 0, sizeof(a));
    }
    void unit(){
        memset(a, 0, sizeof(a));
        a[1][1]=1;
        a[2][2]=1;
    }
    void one(){
        for(int i=1;i<=2;i++){
            for(int j=1; j<=2;j++){
                a[i][j]=1;
            }
        }
    }
    node operator *(const node &x){
        node rt;
        for(int i=1;i<=2;i++){
            for(int j=1; j<=2;j++){
                for(int k=1;k<=2;k++){
                    rt.a[i][j]=(rt.a[i][j]+a[i][k]*x.a[k][j]%mod)%mod;
                }
            }
        }
        return rt;
    }
    void show(){
        hi;
        for(int i=1;i<=2;i++){
            for(int j=1; j<=2;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        hi;
    }
    ll sum(){
        ll ans=0;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                ans=(ans+a[i][j])%mod;
            }
        }
        return ans;
    }
}sum[maxn<<2];
void pushup(int rt){
    //对于编号为rt的节点，他的左右节点分别为rt<<1和rt<<1|1
    sum[rt]=sum[rt<<1]*sum[rt<<1|1];
}

//造树
void build(int l,int r,int rt){
    //建树操作，生成一个区间为l~r的完全二叉树
    
    //如果到底，则线段长度为0，表示一个点，输入该点的值
    if (l==r) {
        sum[rt].one();
        return;
    }
    
    //准备子树
    int m=(l+r)>>1;
    
    //对当前节点建立子树
    build(lson);
    build(rson);
    
    //由底向上求和
    pushup(rt);
}

//更新点和包含点的枝
void update(int pos,int l,int r,int rt){
    //pos为更新的位置 val为增加的值，正则加，负则减
    //l r为区间的两个端点值
    
    //触底，为一个点的时候，该节点值更新
    if (l==r) {
        int x,y;
        scanf("%d%d",&x,&y);
        sum[rt].a[x][y]^=1;
        return;
    }
    
    int m = ( l + r ) >> 1;
    
    if (pos<=m)     //pos在左子树的情况下，对左子树进行递归
        update(pos, lson);
    else            //pos在右子树的情况下，对右子树进行递归
        update(pos, rson);
    
    //更新包含该点的一系列区间的值
    pushup(rt);
}

//查询点或区间
node query(int L,int R,int l,int r,int rt){
    // L~R为被查询子区间 l~r为“当前”树的全区间
    
    if (L<=l&&r<=R)    //子区间包含“当前”树全区间
        return sum[rt]; //返回该节点包含的值
    int m=(l+r)>>1;
    node res;
    res.unit();
    if (L<=m)       //左端点在左子树内
        res=res*query(L, R, lson);
    if (R>m)        //右端点在右子树内
        res=res*query(L, R, rson);
    return res;
}
int main(){
    int n,m,op,x,y,pos;
    while (scanf("%d%d",&n,&m)!=EOF) {
        build(1, n, 1);
        for (int cas=0; cas<m; cas++) {
            scanf("%d",&op);
            if (op==0) {
                scanf("%d%d",&x,&y);
                node tmp = query(x, y-1, 1, n, 1);
//                tmp.show();
                cout<<tmp.sum()<<endl;
            }
            else{
                scanf("%d",&pos);
                update(pos, 1, n, 1);
            }
        }
    }
    return 0;
}
