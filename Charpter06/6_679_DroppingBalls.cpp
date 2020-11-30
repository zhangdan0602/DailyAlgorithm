
#include <cstdio>
#include <cstring>
const int maxd = 20;
int s[1 << maxd];
int main()
{
    int D, I;
    /*
    while (scanf("%d%d", &D, &I) == 2)
    {
        int k = 1;
        for (int i = 0; i <= D - 1; i++)
            if (I % 2)
            {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                I /= 2;
            }
        printf("%d\n", k);
    }
    */

    while (scanf("%d%d", &D, &I) == 2)
    {
        memset(s, 0, sizeof(s));
        int k, n = (1 << D) - 1;
        for (int i = 0; i < I; i++)
        {
            k = 1;
            for (;;)
            {
                s[k] = !s[k];
                k = s[k] ? k * 2 : k * 2 + 1;
                if (k > n)
                    break;
                //最大结点个数为2maxd-1
                //开关 //n是最大结点编号
                //连续让I个小球下落
                //根据开关状态选择下落方向 //已经落“出界”了
            }
        }
        printf("%d\n", k / 2); //“出界”之前的叶子编号 }
    }

    return 0;
}
