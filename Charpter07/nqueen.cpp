#include <cstdio>
#include <cstring>

using namespace std;

int C[50], vis[3][50], tot = 0, nc = 0, n;

void search(int cur)
{
    nc++;
    if (cur == n)
    {
        tot++;
    }
    else
        for (int i = 0; i < n; i++)
        {
            int ok = 1;
            C[cur] = i;
            for (int j = 0; j < cur; j++)
            {
                if (C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                search(cur + 1);
            }
        }
}

void search1(int cur)
{
    nc++;
    if (cur == n)
    {
        tot++;
    }
    else
        for (int i = 0; i < n; i++)
        {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
            {
                C[cur] = i;
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
                search1(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
            }
        }
}
int main()
{
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    search1(0);
    printf("%d\n", tot);
    printf("%d\n", nc);
    return 0;
}