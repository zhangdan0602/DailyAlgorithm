#include <cstdio>
#include <algorithm>

using namespace std;

int A[101], P[101];

void print_permutation_0(int n, int *A, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        { //尝试在A[cur]中填各种整数i
            int ok = 1;
            for (int j = 0; j < cur; j++)
                if (A[j] == i)
                {
                    ok = 0; //如果i已经在A[0]~A[cur-1]出现过，则不能再选
                }

            if (ok)
            {
                A[cur] = i;
                print_permutation_0(n, A, cur + 1); //递归调用
            }
        }
    }
}

void print_permutation_1(int n, int *P, int *A, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else
        //之前的禁止A重复
        for (int i = 0; i < n; i++)
        {
            if (!i || P[i] != P[i - 1])
            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < cur; j++)
                    if (A[j] == P[i])
                        c1++;
                for (int j = 0; j < n; j++)
                    if (P[i] == P[j])
                        c2++;
                //一个解决方法是统计A[0]~A[cur-1]中P[i]的出现次数c1，以及P数组中P[i]的出现次数 c2。只要c1<c2，就能递归调用。
                if (c1 < c2)
                {
                    A[cur] = P[i];
                    print_permutation_1(n, P, A, cur + 1);
                }
            }
        }
}

int main()
{
    int n;
    scanf("%d", &n);
    print_permutation_0(n, A, 0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &P[i]);
    }
    sort(P, P + n);
    print_permutation_1(n, P, A, 0);

    int m, p[10];
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p[i]);
    }
    sort(p, p + m);
    do
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
    } while (next_permutation(p, p + m));
    return 0;
}