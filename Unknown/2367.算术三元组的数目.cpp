/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    int res = 0, n = nums.size();
    auto&& d = diff * 2;
    unordered_set<int> pos(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
      for (int k = n - 1; k > i + 1; k--) {
        auto&& now = nums[k] - nums[i];
        if (now < d) break;
        if (now == d) {
          auto&& need = nums[k] - diff;
          if (pos.count(need)) res++;
          break;
        }
      }
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
