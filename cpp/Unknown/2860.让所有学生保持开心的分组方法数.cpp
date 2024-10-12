/*
 * Created by 张明利 on 2024年10月12日星期六 11:42:56
 */

/*
 * @lc app=leetcode.cn id=2860 lang=cpp
 *
 * [2860] 让所有学生保持开心的分组方法数
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int countWays(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int out = 0;
    int n = nums.size();
    for (int i = -1; i < n; ++i)
      out +=
          (i == -1 || nums[i] < i + 1) && (i + 1 == n || nums[i + 1] > i + 1);

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
