#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Matrix
{
    /* data */
    int a, b;
    Matrix(int a = 0, int b = 0) : a(a), b(b) {}
} m[26];

stack<Matrix> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while (cin >> expr)
    {
        bool error = false;
        int ans = 0;
        for (int i = 0; i < expr.length(); i++)
        {
            /* code */
            if (isalpha(expr[i]))
            {
                s.push(m[expr[i] - 'A']);
            }
            else if (expr[i] == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if (m2.a != m1.b)
                {
                    error = true;
                    break;
                }
                else
                {
                    ans += m1.a * m1.b * m2.b;
                }
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if (error)
        {
            printf("error\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}