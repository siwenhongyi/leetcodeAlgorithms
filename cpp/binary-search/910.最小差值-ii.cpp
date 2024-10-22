/*
 * Created by 张明利 on 2024年10月22日星期二 10:52:37
 */

/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int smallestRangeII(vector<int>& n, int k) {
    sort(begin(n), end(n));
    int out(n.back() - n.front());
    for (int i{1}; i < size(n); ++i)
      out = min(out,
                max(n[i - 1] + k, n.back() - k) - min(n[i] - k, n.front() + k));
    return out;
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
