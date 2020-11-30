/*
某城市有一个火车站，铁轨铺设如图6-1所示。有n节车厢从A方向驶入车站，按进站顺 序编号为1~n。你的任务是判断是否能让它们按照某种特定的顺序进入B方向的铁轨并驶出 车站。例如，出栈顺序(5 4 1 2 3)是不可能的，但(5 4 3 2 1)是可能的。
// UVa 514
*/

#include <cstdio>
#include <stack>

using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        stack<int> s;
        int A = 1, B = 1;
        for (int i = 1; i <= n; i++)
        {
            /* code */
            scanf("%d", &target[i]);
        }
        int ok = 1;
        while (B <= n)
        {
            if (A == target[B])
            {
                /* code */
                A++;
                B++;
            }
            else if (!s.empty() && s.top() == target[B])
            {
                /* code */
                s.pop();
                B++;
            }
            else if (A <= n)
            {
                /* code */
                s.push(A++);
            }
            else
            {
                ok = 0;
                break;
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
    }
    return 0;
}