#include <cstdio>
#include <cstring>

using namespace std;

int A[16], n, isp[16], vis[16];

int is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int cur)
{
    if (cur == n && isp[A[0] + A[n - 1]])
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i] && isp[i + A[cur - 1]])
            {
                vis[i] = 1;
                A[cur] = i;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    int kase = 0;
    while (scanf("%d", &n) == 1 && n > 0)
    {
        if (kase > 0)
        {
            printf("\n");
        }
        printf("Case %d:\n", ++kase);
        for (int i = 2; i <= 2 * n; i++)
        {
            isp[i] = is_prime(i);
        }
        memset(vis, 0, sizeof(vis));
        A[0] = 1;
        dfs(1);
    }
    return 0;
}