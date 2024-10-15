/*
 * Created by 张明利 on 2024年10月15日星期二 10:51:02
 */

/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  int testDrop(int k, int n, vector<vector<int>>& maybe) {
    if (n <= 1) return n;
    if (k == 1) return n;
    if (maybe[k][n] != -1) return maybe[k][n];
    int res = 1 << 30, l = 0, r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      int ll = testDrop(k - 1, m - 1, maybe), rr = testDrop(k, n - m, maybe);
      if (ll < rr) {
        l = m + 1;
      } else {
        r = m - 1;
      }
      res = min(res, 1 + max(ll, rr));
    }
    maybe[k][n] = res;
    return res;
  }

 public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return testDrop(k, n, dp);
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
