#include <cstdio>

using namespace std;

int A[10], B[10];

//1.增量法
void print_subset1(int n, int *A, int cur)
{
    for (int i = 0; i < cur; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++)
    {
        A[cur] = i;
        print_subset1(n, A, cur + 1);
    }
}

//2.位向量
void print_subset2(int n, int *B, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < cur; i++)
        {
            if (B[i])
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        return;
    }
    B[cur] = 1;
    print_subset2(n, B, cur + 1);
    B[cur] = 0;
    print_subset2(n, B, cur + 1);
}

//3.二进制法
void print_subset3(int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (s & (1 << i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    print_subset1(n, A, 0);
    print_subset2(n, B, 0);
    for (int i = 0; i < (1 << n); i++)
    {
        print_subset3(n, i);
    }

    return 0;
}