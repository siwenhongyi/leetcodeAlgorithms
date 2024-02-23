/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using ll = long long;

 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0, j, k, p;
    vector<vector<int>> res;
    while (i < n - 3) {
      j = i + 1;
      auto&& a = nums[i];
      while (j < n - 2) {
        k = j + 1, p = n - 1;
        auto&& b = nums[j];
        while (k < p) {
          auto&& sum = (ll)a + b + nums[k] + nums[p];
          if (sum == target) {
            res.push_back({a, b, nums[k++], nums[p--]});
            while (k < p && nums[k] == nums[k - 1]) k++;
            while (p > k && nums[p] == nums[p + 1]) p--;
          } else if (sum > target)
            p--;
          else
            k++;
        }
        while (++j < n - 2 && nums[j] == nums[j - 1]) (0);
      }
      while (++i < n - 3 && nums[i] == nums[i - 1]) (0);
    }
    return res;
  }
};
// @lc code=end
