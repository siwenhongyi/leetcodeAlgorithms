/*
 * Created by 张明利 on 2024年10月15日星期二 10:49:45
 */

/*
 * @lc app=leetcode.cn id=1884 lang=cpp
 *
 * [1884] 鸡蛋掉落-两枚鸡蛋
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  int a(int n) {
    static unordered_map<int, int> m{{0, 0}};
    if (m.count(n)) return m[n];
    int out{INT_MAX};
    for (auto j{0}; j < n; ++j) out = min(out, 1 + max(a(j), n - j - 1));
    return m[n] = out;
  }
  int b(int n) {
    int out{};
    for (int i{}; n; --n)
      if (++i > out) out = i, i = 1;
    return out;
  }
  int c(int n) { return (1 + sqrt(8.0 * n - 7)) / 2; }

 public:
  int twoEggDrop(int n) {
    /*
    Using some math magic you can come up with the formula to solve the problem
    in `O(1)`. The key is to derive integer inverse function of the triangular
    numbers **trinv(n)** and to shift it by `1`. <br>
    ![image](https://assets.leetcode.com/users/images/0db66a56-f16d-47f8-82f8-4f27ac06b6f7_1622829604.721454.png)
    */
    return c(n);
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
