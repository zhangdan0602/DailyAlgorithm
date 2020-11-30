/*
输入正整数k，找到所有的正整数x≥y，使得1/k = 1/x + 1/y.
样例输入:
2
12
样例输出:
2
1/2 = 1/6 + 1/3
1/2 = 1/4 + 1/4
8
1/12 = 1/156 + 1/13
1/12 = 1/84 + 1/14 
1/12 = 1/60 + 1/15 
1/12 = 1/48 + 1/16 
1/12 = 1/36 + 1/18 
1/12 = 1/30 + 1/20 
1/12 = 1/28 + 1/21 
1/12 = 1/24 + 1/24
【分析】
既然要求找出所有的x、y，枚举对象自然就是x、y了。
可问题在于，枚举的范围如何? 从1/12=1/156+1/13可以看出，x可以比y大很多。难道要无休止地枚举下去?当然不是。
由于x≥y，有1/x <= 1/y ，因此1/k - 1/y <= 1/y, 即y <= 2k. 这样，只需要在2k范围之内枚举y，然后根据y尝试因此计算出x即可。
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    while (cin >> k && k)
    {
        vector<int> X, Y;
        for (int y = k + 1; y <= 2 * k; y++)
        {
            if ((k * y) % (y - k) == 0)
            {
                int x = (k * y) / (y - k);
                if (x >= y)
                {
                    X.push_back(x);
                    Y.push_back(y);
                }
            }
        }
        printf("%lu\n", X.size());
        for (int i = 0; i < X.size(); i++)
        {
            printf("1/%d = 1 / %d + 1 / %d\n", k, X[i], Y[i]);
        }
    }
    return 0;
}