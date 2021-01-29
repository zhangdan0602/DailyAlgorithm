//
// Created by ZD-Mac on 2021-01-26.
//

/*
 * 给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

 

示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1
 

提示：

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
//        int res = 0;
//        for (int i = 0; i < dominoes.size(); ++i) {
//            for (int j = i + 1; j < dominoes.size(); ++j) {
//                if ((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1])
//                    || (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])) {
//                    res++;
//                }
//            }
//        }
//        return res;
        int res = 0;
        vector<int> nums(100);
        for (auto &it:dominoes) {
            int num = it[0] < it[1] ? it[0] * 10 + it[1] : it[0] + it[1] * 10;
            res += nums[num];
            nums[num]++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> dominoes = {{1, 2},
                                    {2, 1},
                                    {3, 4},
                                    {5, 6}};
    int res = solution.numEquivDominoPairs(dominoes);
    cout << res << endl;
    return 0;
}
