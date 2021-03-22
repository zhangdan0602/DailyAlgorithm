//
// Created by ZD-Mac on 2021/3/9.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// 快速幂
int power2(int a, int b, int c) {
    int res = 1;
    a %= c;
    while (b) {
        if (b & 1)
            res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}

bool cmp(int a, int b) {
    if (a % 2 == b % 2)//如果同奇同偶
        return a < b;//直接从小到大排序
    else//如果奇偶性不同
        return (a % 2) > (b % 2);//奇数在偶数前
}

struct node {
    double w, m;
} p[1005];

bool cmp1(node a, node b) {
    //按照每毫升的价格从低到高排序
    return a.w / a.m < b.w / b.m;
}

int main() {
    char s[105];
//    gets(s);//例如输入how are you?
//    printf("%s\n", s);//how are you?
//    scanf("%s", s);//例如输入how are you?
//    printf("%s\n", s);//how

//    cin >> s;//例如输入how are you?
//    cout << s;//how

    // 输入为字符时，使用%s；如果使用%c的话，换行算一个字符
//    char mpt[10][10];
//    for (int i = 1; i <= 4; i++) {
//        scanf("%s", mpt[i] + 1);
//    }
//    for (int i = 1; i <= 4; i++) {
//        for (int j = 1; j <= 4; j++) {
//            printf("%c", mpt[i][j]);
//        }
//        printf("\n");
//    }

    // 数组存储索引数为数，值为个数；索引数为个数，值为数的最大值
    // 请将每个不同的数从小到大输出并且输出它对应的个数。
//    int f[105] = {0};//注意，尽量将数组开在全局
//    int n, x;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        f[x]++;
//    }
//    for (int i = 0; i <= 100; i++) {
//        if (f[i] > 0) printf("%d %d\n", i, f[i]);
//    }

    // 请将每个不同的数从小到大输出并且输出它对应的个数。如果多个值有相同的个数，输出值最大的那个。
//    int f[105] = {0};
//    int p[105] = {0};//p[i]表示有i个这样的数的最大值是多少
//    int n, x;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        f[x]++;
//    }
//    for (int i = 0; i <= 100; i++) p[f[i]] = i;
//    for (int i = 1; i <= 100; i++) {
//        if (p[i] > 0) printf("%d %d\n", p[i], i);
//    }

    // 使用迭代器遍历 map 的 key 和 value
//    map<string, int> dict;//定义一个map
//    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
//        cout << it->first << " is in class " << it->second << endl;
//    }
//    dict.clear();//清空 map

    // 进制转换问题 n诺p30-p34

    // 排序先奇偶排序后大小排序
//    int n;
//    int a[1005] = {0};
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    sort(a, a + n, cmp);
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;

    // 贪心，注意排序
//    int n, x;
//    while (scanf("%d%d", &x, &n) != EOF) {
//        if (x == -1 && n == -1) break;
//        for (int i = 1; i <= n; i++) {
//            scanf("%lf%lf", &p[i].m, &p[i].w);
//        }
//        sort(p + 1, p + 1 + n, cmp);
//        double ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (x >= p[i].w) {//如果剩余的钱能全买
//                ans += p[i].m;
//                x -= p[i].w;
//            } else {//如果剩余的钱买不完这种饮料
//                ans += (p[i].m * x / p[i].w);
//                break;//到这里 x 已经为 0 了
//            }
//        }
//        printf("%.3lf\n", ans);
//    }

    // 同模 p68-69

    // 大数相加 90
    
    return 0;
}