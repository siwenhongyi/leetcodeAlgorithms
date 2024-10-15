/*
 * Created by 张明利 on 2024年10月15日星期二 10:52:19
 */

/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 *
 * [2848] 与车相交的点
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    if (nums.empty()) return 0;
    int res = 0;
    sort(nums.begin(), nums.end());
    // nums.push_back({nums.back().back() + 1, 0});
    int l = nums[0][0], r = nums[0][1];
    for (const auto& car : nums) {
      if (car[0] <= r) {
        r = max(r, car[1]);
        continue;
      }
      res += r - l + 1;
      l = car[0], r = car[1];
    }
    res += r - l + 1;
    return res;
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
