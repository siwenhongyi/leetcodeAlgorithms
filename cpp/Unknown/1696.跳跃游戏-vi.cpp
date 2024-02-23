/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    /*
    dp[i][j] 表示i-j 最大得分
    dp[i][j] = nums[i] + dp[i+x][j] (x->1,k)
    */
    int n = nums.size();
    vector<int> dp(n, 0);
    // 缓存右侧k位所有dp以及对应数量
    map<int, int, greater<int>> pre_max_cnt;
    dp.back() = nums.back();
    pre_max_cnt[dp.back()]++;
    int had_size = 1;
    auto it = pre_max_cnt.begin();
    for (int i = n - 2; i >= 0; i--) {
      // 加上右侧k位内最大的dp
      dp[i] = nums[i] + it->first;
      // 够k个 删除最早的dp值
      if (had_size == k) {
        // 不再存在这个值 删除之
        if (--pre_max_cnt[dp[i + k]] == 0) {
          pre_max_cnt.erase(dp[i + k]);
        }
      } else
        had_size++;
      // 新增dp
      pre_max_cnt[dp[i]]++;
      // 寻找最大的dp
      it = pre_max_cnt.begin();
    }
    // for (auto& it : dp) cout << it << ' ';
    // cout << endl;
    return dp.front();
  }
};
// @lc code=end
