/*
输入正整数n，按从小到大的顺序输出所有形如abcde/fghij = n的表达式，其中a~j恰好
为数字0~9的一个排列(可以有前导0)，2≤n≤79。 样例输入:
62
样例输出:
79546 / 01283 = 62
94736 / 01528 = 62
【分析】
枚举0~9的所有排列?没这个必要。只需要枚举fghij就可以算出abcde，然后判断是否所有数字都不相同即可。
不仅程序简单，而且枚举量也从10!=3628800降低至不到1万，而且 当abcde和fghij加起来超过10位时可以终止枚举。
由此可见，即使采用暴力枚举，也是需要认真分析问题的。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, kase = 0;
    char buf[99];
    while (scanf("%d", &n) == 1 && n)
    {
        int cnt = 0;
        if (kase++)
        {
            printf("\n");
        }
        for (int fghij = 1234;; fghij++)
        {
            int abcde = fghij * n;
            sprintf(buf, "%05d%05d", abcde, fghij);
            if (strlen(buf) > 10)
            {
                break;
            }
            sort(buf, buf + 10);
            bool ok = true;
            for (int i = 0; i < 10; i++)
            {
                if (buf[i] != i + '0')
                {
                    ok = false;
                }
            }
            if (ok)
            {
                cnt++;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if (!cnt)
        {
            printf("There are no solutions for %d.\n", n);
        }
    }

    return 0;
}