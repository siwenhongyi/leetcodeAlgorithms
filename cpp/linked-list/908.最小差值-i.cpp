/*
 * Created by 张明利 on 2024年10月22日星期二 10:56:45
 */

/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int smallestRangeI(vector<int>& n, int k) {
    sort(begin(n), end(n));
    int res = n.back() - k - n.front() - k;
    return res < 0 ? 0 : res;
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
