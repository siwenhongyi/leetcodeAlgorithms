/*
 * @lc app=leetcode.cn id=2547 lang=cpp
 *
 * [2547] 拆分数组的最小代价
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int minCost(vector<int>& nums, int k) {
    /*
    f[i] = 前i个元素最小代价  Res = f[n];
    t[i][j]= 区间 [i,j] 的代价 每次直接使用  不存储
    f[i] = min(f[i], f[j] + t[j][i]);
    unique_size 区间唯一出现数字的数量
    already 出现个数
    暴力计算每个区间的代价？
    */
    int n = nums.size();
    vector<int> f(n + 1, (1 << 30));
    f[0] = 0;
    // vector<vector<int>> t(n, vector<int>(n + 1, 0));
    unordered_map<int, int> already;
    int unique_size = 0;
    for (int i = 1; i <= n; i++) {
      already.clear();
      unique_size = 0;
      // 计算t[j][i]
      for (int j = i - 1; j >= 0; j--) {
        auto&& cnt = ++already[nums[j]];
        if (cnt == 1)
          unique_size++;
        else if (cnt == 2)
          unique_size--;
        // t[j][i] = k + i - j - unique_size;
        f[i] = min(f[i], f[j] + k + i - j - unique_size);
      }
    }
    return f.back();
  }
};
// @lc code=end
