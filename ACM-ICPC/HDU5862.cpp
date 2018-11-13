// Wrote by MenYifan on 2016-08-19 16:38:51
// Exe.Time 2293ms Exe.Memory 11596K
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long  c[500011];
int lowbit(int x)//?????ci???????????;
{
    return x & (-x);
}
void update(int i, long long  x, int n, long long *c)
{
    while (i <= n)
    {
        c[i] = c[i] + x;
        i = i + lowbit(i);
    }
}
long long  sum(int i, long long  c[])
{
    long long  ans = 0;
    while (i > 0)
    {
        ans = ans + c[i];
        i = i - lowbit(i) ;
    }
    return ans;
}

struct po
{
    int l, r, h;
    friend bool operator< (po x, po y)
    {
        return x.r >= y.r;
    }
} x[100010], y[100010];
struct query
{
    int flag;
    int l, r, h;
    int where;
} node[300010];

bool cmp(query a, query b)
{
    if(a.where != b.where)
    {
        return   a.where < b.where;
    }
    return a.flag < b.flag;
}

int mark[500010];


int dd(int X, int where)
{
    return lower_bound(mark, mark + where, X) - mark + 1;
}

int main ()
{
    ///freopen("1006.in", "r", stdin);
    ///freopen("1006.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(c, 0, sizeof(c));
        memset(mark, 0, sizeof(mark));
        int n;
        scanf("%d", &n);
        int numx = 0;
        int numy = 0;
        for (int i = 0; i < n; i++)
        {
            int A, B, C, D;
            scanf("%d%d%d%d", &A, &B, &C, &D);
            mark[4 * i] = A;
            mark[4 * i + 1] = B;
            mark[4 * i + 2] = C;
            mark[4 * i + 3] = D;
            if(B == D)
            {
                //cout <<i<<endl;
                x[numx].l = min(A, C);
                x[numx].r = max(A, C);
                x[numx].h = B;
                numx++;
            }
            else
            {
                y[numy].l = min(B, D);
                y[numy].r = max(B, D);
                y[numy].h = A;
                numy++;
            }
        }
        sort( mark, mark + 4 * n);
        int where = unique(mark, mark + 4 * n) - mark;
        int num = 0;
        for (int i = 0; i < numx; i++)
        {
            node[num].where = dd(x[i].l, where);
            node[num].h = dd(x[i].h, where);
            node[num].flag = 1;
            num++;
            node[num].where = dd(x[i].r, where);
            node[num].h = dd(x[i].h, where);
            node[num].flag = 3;
            num++;

        }
        for (int i = 0; i < numy; i++)
        {
            node[num].where = dd(y[i].h, where);
            node[num].l = dd(y[i].l, where);
            node[num].r = dd(y[i].r, where);
            node[num].flag = 2;
            num++;
        }
        sort (node, node + num, cmp);
        long long ans = 0LL;
        for (int i = 0; i < num; i++)
        {
            if(node[i].flag == 1)
            {
                update(node[i].h, 1, where + 1, c);
            }
            if(node[i].flag == 3)
            {
                update(node[i].h, -1, where + 1, c);
            }
            if(node[i].flag == 2)
            {
                ans += sum(node[i].r, c) - sum(node[i].l - 1, c);
            }
        }
        printf("%I64d\n", ans);

    }
}