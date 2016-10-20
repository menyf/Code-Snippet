// Wrote by MenYifan on 2016-03-31 20:47:10
// Exe.Time 873ms Exe.Memory 4300K
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define mod 1000000007
#define maxn 100005
int arr[maxn];
long long view[maxn];
long long l[maxn];
long long r[maxn];
int main()
{
        int n;
        while (~scanf("%d", &n))
        {
                for (int i = 1; i <= n; i++)
                {
                        scanf("%d", arr + i);
                }

                for (int i = 1; i <= maxn; i++)
                {
                        l[i] = 0;
                        view[i] = 0;
                }

                for (int i = 1; i <= n; i++)
                {
                        for (int j = 1; j * j <= arr[i]; j++)
                        {
                                if (arr[i] % j == 0)
                                {
                                        l[i] = max(l[i], view[j]);
                                        l[i] = max(l[i],view[arr[i]/j]);
                                }
                        }
                        view[arr[i]] = i;
                }

                for (int i = 1; i <= maxn; i++)
                {
                        r[i] = n + 1;
                        view[i] = n + 1;
                }

                for (int i = n; i >= 1; i--)
                {
                        for (int j = 1; j * j <= arr[i]; j++)
                        {
                                if (arr[i] % j == 0)
                                {
                                        r[i] = min(r[i], view[j]);
                                        r[i] = min(r[i],view[arr[i]/j]);
                                }
                        }
                        view[arr[i]] = i;
                }
                long long ans = 0;
                for (long long i = 1; i <= n; i++)
                {
                        ans += (i - l[i]) * (r[i] - i);
                        ans %= mod;
                }
                printf("%I64d\n", ans);
        }
        return 0;
}
