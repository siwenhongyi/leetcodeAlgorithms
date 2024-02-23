/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i < n; i++) {
      bool flag = dp[i + 1];
      if (nums[i] == nums[i - 1]) {
        flag |= dp[i - 1];
      }
      if (i >= 2 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
        flag |= dp[i - 2];
      }
      if (i >= 2 && nums[i] - nums[i - 1] == 1 &&
          nums[i - 1] - nums[i - 2] == 1) {
        flag |= dp[i - 2];
      }
      dp[i + 1] = flag;
    }
    for (auto&& it : dp) cout << it << ' ';
    return dp.back();
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  auto it = vector<int>{4, 4, 4, 5, 6};
  cout << Solution().validPartition(it) << endl;
  auto it = vector<int>{1, 1, 1, 2};
  cout << Solution().validPartition(it) << endl;

  return 0;
}
