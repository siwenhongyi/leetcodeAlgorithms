/*
 * Created by 张明利 on 2024年10月12日星期六 17:25:07
 */

/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 *
 * [2576] 求出最多标记下标
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    unordered_set<int> t;
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    int j = n / 2;
    for (int i = 0; i < n; i++) {
      if (t.find(i) != t.end()) continue;
      while (j < n && (t.find(j) != t.end() || nums[j] * 2 > nums[i])) j++;
      if (j == n) break;
      t.insert(i), t.insert(j++);
    }
    return t.size();
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
